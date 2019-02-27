using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/* ===== Message handler thread ==================
MsgHandler thread is created every time when hand terminal sends data and destroyed immediately after data has been handled
Data syncronization and other multithreading features of C# must be used in order to safely access common data
For example, listbox control cannot be accessed from thread because it is not created from thread.
Therefore, _list "data storage" is used to store data from hand terminal and then Timer of main application is used to move collected data in to the listbox control.
Storing data safely to _list object from MsgHandler can be done using "lock" sync object of C#
*/

namespace C_Sharp_MultiThread
{
    static class cons
    {
        //Here are all the constant definitions

        //Main menu button positions
        public const byte POS_FORM_1_BUT = 45;
        public const byte POS_FORM_2_BUT = 65;

        //Form ID's
        public const byte MAIN_FORM = 100;
        public const byte FORM_1 = 101;
        public const byte FORM_2 = 102;

        //NewField(Ex) style flags
        public const byte STYLE_SND_ENTER = 1;
        public const byte STYLE_NO_SEND = 2;
        public const byte STYLE_SND_ALL = 4;
        public const byte STYLE_FLD_LOCK = 8;
        public const byte STYLE_OVR = 16;
        public const byte STYLE_FLD_READER = 32;
        public const byte STYLE_READER_DEFAULT = 64;
        public const byte STYLE_FLD_ACTIVE = 128;
        
        //FieldCmd flags
        public const byte FLD_REMOVE = 1;
        public const byte FLD_CLEAR = 2;
        public const byte FLD_LOCK = 8;       
        public const byte FLD_ACTIVE = 128;
    }

    class MsgHandler
    {
        public AxPLSERVERLib.AxPLServer pl;
        public AxPLSERVERLib._DPLServerEvents_DataArrivedEvent e; //This parameter is passed to this thread
        
        public void MsgHandlerThread()
        {            
            //First we need to know, is there form in HS where data is coming from (not initial screen)
            int formID = pl.GetFormID(e.id);
            
            if (formID==0)
            {
                //No existing form. Let's send Main menu
                SendMainMenu();
                //Answer has been sent to HS. We are done. Exit thread
                return;
            }
            else if (formID == cons.MAIN_FORM)
            {
                DataFromMainMenu();
            }
            else if (formID == cons.FORM_1)
            {
                DataFromForm1();
            }
            else if (formID == cons.FORM_2)
            {
                DataFromForm2();
            }
            else
            {
                SendMainMenu();
            }

            //There should not be situation that program execution reaches this point without giving answer to HS
        }

        private void SendMainMenu()
        {
            //Prepare main menu UI controls
            pl.ClearForm(e.id);  //Clear the screen from existing UI controls
            pl.TextEx(e.id, 3, "* Main menu*");
            pl.Button(e.id, cons.POS_FORM_1_BUT, "Scan code");
            pl.Button(e.id, cons.POS_FORM_2_BUT, "Fill and send");        

            //Set formID
            pl.SetFormID(e.id, cons.MAIN_FORM);
            //Send all
            pl.Send(e.id, cons.MAIN_FORM);
        }
        private void DataFromMainMenu()
        {
            if (e.frameid == -1)
            {
                //F-key pressed. Just send Ack which doesn't do anything but HS is happy
                pl.Ack(e.id);
                pl.Send(e.id, -1);
                return;
            }
            //Check which one has been pressed
            if(pl.IsData(e.id, cons.POS_FORM_1_BUT) == true) 
                SendForm1();
            if(pl.IsData(e.id, cons.POS_FORM_2_BUT) == true)
                SendForm2();       
        }

        private void SendForm1()
        {
            pl.ClearForm(e.id);
            pl.TextEx(e.id, 0, "**** Scan code ****");
            pl.TextEx(e.id, 20, "Press F-key to exit");
            pl.NewFieldEx(e.id, 80, 13, cons.STYLE_SND_ENTER + cons.STYLE_FLD_READER + cons.STYLE_FLD_ACTIVE + cons.STYLE_OVR);
            pl.SetFormID(e.id, cons.FORM_1);
            pl.Send(e.id, cons.FORM_1);
        }

        private void DataFromForm1()
        {
            string code;

            if (e.frameid == -1)
            {
                //F-key pressed, send mainmenu
                SendMainMenu();
                return;
            }

            code = pl.GetData(e.id, 80);
            lock (Form1._list) Form1._list.Add (code);

           //Giving answer to HS
            pl.PopMessage(e.id, 20, "Thanks for the code: " + code);
            pl.FieldCmd(e.id, 40, 2); //Clears the field
            pl.Send(e.id, -1);
        }

        private void SendForm2()
        {
            pl.ClearForm(e.id);
            pl.TextEx(e.id, 0, "  *fill and [Send]*");
            pl.NewFieldEx(e.id, 42, 13, cons.STYLE_FLD_READER + cons.STYLE_FLD_ACTIVE);
            pl.NewFieldEx(e.id, 62, 13, cons.STYLE_FLD_READER);
            pl.NewFieldEx(e.id, 82, 13, cons.STYLE_FLD_READER);
        
            //Creating input which is locked.
            //When user press that, all contents from all input fields are sent.
            pl.NewField(e.id,127,6,cons.STYLE_NO_SEND+cons.STYLE_SND_ENTER+cons.STYLE_SND_ALL+cons.STYLE_FLD_LOCK);
            pl.FldTxt(e.id,127,"[Send]");           

            //Exit button
            pl.NewField(e.id,147,6,cons.STYLE_NO_SEND+cons.STYLE_SND_ENTER+cons.STYLE_FLD_LOCK);
            pl.FldTxt(e.id,147,"[Exit]");           
        
            //Ready to send. Set Form ID and send
            pl.SetFormID(e.id, cons.FORM_2);
            pl.Send(e.id, cons.FORM_2);
        }

        private void DataFromForm2()
        {
            string code;
           
            //There is three possibilites of user actions:

            //1. if F-key has been pressed (causing handterminal to send F-key string immediately)
            if (e.frameid == -1)
            {
                //F-Key pressed
                code = pl.GetData(e.id, -1);
                pl.PopMessage(e.id, 29, code);//We just give back F-key string as a popmessage
                pl.Bell(e.id);//With extral bell sound
                pl.Send(e.id, -1); //Note: frameid = -1 means that sameframe id as before. Set/GetFormID replaces frameID
                return;
            }
            //2. User press OK over [Send] button
            if (pl.IsData(e.id, 127))
            {
                //[Send] pressed. Get data from fields and send them to _list      
                //timer in the application main form takes care of string adding in to the listbox control
                lock (Form1._list) Form1._list.Add(pl.GetData(e.id, 42));
                lock (Form1._list) Form1._list.Add(pl.GetData(e.id, 62));
                lock (Form1._list) Form1._list.Add(pl.GetData(e.id, 82));

                //Now data has been collected and we can send answer to HS
                pl.Bell(e.id);
                pl.Bell(e.id);
                pl.FieldCmd(e.id, 42, cons.FLD_CLEAR + cons.FLD_ACTIVE);
                pl.FieldCmd(e.id, 62, cons.FLD_CLEAR );
                pl.FieldCmd(e.id, 82, cons.FLD_CLEAR );
                pl.Send(e.id, -1);
                return;
            }
            //3. User press [Exit] button. Send Main menu
            if (pl.IsData(e.id, 147))
            {
                SendMainMenu();
                return;
            }

            //there should be no way to reach this point
            //but if so, send just ACK
            pl.Ack(e.id);
            pl.Send(e.id,-1);
        }

      

    }
}
