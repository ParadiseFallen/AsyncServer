using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    class Client : IDisposable
    {
        public string Name { get; set; }
        public IPEndPoint ServerPoint;

        public async void  Start()
        {
            Console.WriteLine("Enter name : ");
            Name = Console.ReadLine();
            string adress;
            Console.WriteLine("Enter server adress : ");
            adress = Console.ReadLine();
            int port;
            Console.WriteLine("Enter server port : ");
            port = int.Parse(Console.ReadLine());
            ServerPoint = new IPEndPoint(IPAddress.Parse(adress), port);
            Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //socket.Bind(ServerPoint);
            socket.Connect(ServerPoint);
            socket.Send(await NetPacket.Serialazie(new NetPacket() { DataType = NetPacket.ObjectType.CONECT, Data = Name }));
            bool exit = false;
            do
            {

                Console.WriteLine("Enter test : ");
                string test = Console.ReadLine();

                if (test.Contains("exit"))
                    exit = true;

                NetPacket packet = new NetPacket() { Data = test, DataType = NetPacket.ObjectType.TEXT };
                var t = NetPacket.Serialazie(packet);
                socket.Send(t.Result);
                Console.WriteLine("Send");

            } while (!exit);
            socket.Send(await NetPacket.Serialazie(new NetPacket() { DataType = NetPacket.ObjectType.DISCONECT, Data = Name }));
            socket.Shutdown(SocketShutdown.Both);
        }

        public void Dispose()
        {

        }
    }
}
