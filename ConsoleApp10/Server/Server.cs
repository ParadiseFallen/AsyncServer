using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    class Server : IDisposable
    {
        public IPEndPoint EndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 2555);
        //public IPEndPoint EndPoint =  Dns.
        public bool Active { get; set; } = true;

        public void Dispose()
        {
        }

        public void Start()
        {
            try
            {
                var MainSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                MainSocket.Bind(EndPoint);
                MainSocket.Listen(100);
                Console.WriteLine($"Server run on {EndPoint.Address}:{EndPoint.Port}");
                do
                {
                    HandleClient(MainSocket.Accept());
                } while (Active);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                Console.WriteLine("Server failure!");
                Console.ReadKey();
            }

        }


        private async void HandleClient(Socket s)
        {
            Task.Run(() => { });
            NetPacket packet;
            do
            {
                packet = await NetPacket.Deserialize(s, 1024);
                switch (packet.DataType)
                {
                    case NetPacket.ObjectType.MESSAGE:
                        break;
                    case NetPacket.ObjectType.TEXT:
                        Console.WriteLine(packet.Data);
                        break;
                    case NetPacket.ObjectType.CONECT:
                        Console.WriteLine($"Client conected with name : {packet.Data}");
                        break;
                    case NetPacket.ObjectType.DISCONECT:
                        Console.WriteLine($"Client disconect with name : {packet.Data}");
                        break;
                    default:
                        break;
                }
            } while (packet.DataType != NetPacket.ObjectType.DISCONECT);
        }
    }
}
