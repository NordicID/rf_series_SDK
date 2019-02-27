using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace C_Sharp_MultiThread
{
    public partial class Form1 : Form
    {
        public static List<string> _list = new List<string>();
 
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //This is good point to open base station connections
            //You can use also "BS connection" button but connections can be also defined following way.

            axPLServer1.Connect(1);//Connect to COM 1
            //axPLServer1.StartServer(3001);//Listening base station connections. (PC-Emulator connects to this type of conn)
            //axPLServer1.ConnectToSerialServer("194.100.81.91",2101); //Connect to BS which is server            
            
        }

        private void axPLServer1_DataArrived(object sender, AxPLSERVERLib._DPLServerEvents_DataArrivedEvent e)
        {
            //This event is fired when user of hand terminal sends data to us.
            //Now hand terminal waits answer. We need to handle message as fast as possible.
            //PLServer "ID box" is red. (hardly seen)
            //After "Send" method has been called, "ID Box" is turning to green"

            //It's also possible that third party hand terminal message is received. In that case, you just do nothing with that message.
            //There are couple ways to prevent third party access.
            //1. Allow only specified commID's to communicate (in this event handler parameter e.id = commID)
            //2. Use Login scheme to verify user of hand terminal. 
            //commID validation should be very first job when staring to handle HS message. This demo doesn't implement it.

            // at this point, we create separate thread to process hand terminal message
            // It's important to exit from this handler as fast as possible for allowing other hand terminal messages to be processed fast.

             MsgHandler worker = new MsgHandler();
             Thread workerThread = new Thread(worker.MsgHandlerThread);

            //Params to thread  
            worker.pl = axPLServer1; //PLServer object
            worker.e=e;              //Params from this event
            //Start thread and exit      
            workerThread.Start();
            
        }
                
        private void timer1_Tick(object sender, EventArgs e)
        {
            //Timer is used for printing collected items in the listBox (checked every 100ms)
            //Data handler threads cannot access directly to listBox object so data is first collected to _list array
            //After adding data to listbox _list array will be cleared

            string[] items;

            if (listBox1.Items.Count > 72) listBox1.Items.Clear();//too many itens. Clear it

            lock (_list) //making sure that only we can go to manipulate _list array
            {
                items = _list.ToArray();
                _list.Clear();
            }

            foreach (string s in items) listBox1.Items.Add(s);
            

        }

        private void BSCONN_BUT_Click(object sender, EventArgs e)
        {
            axPLServer1.OpenBSConnections();
        }
                


    }
}
