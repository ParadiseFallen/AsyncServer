using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    [Serializable]
    public class NetPacket
    {
        public enum ObjectType { MESSAGE, TEXT,CLEAR, DISCONECT,CONECT }
        public ObjectType DataType { get; set; }
        public object Data { get; set; }
        static public async Task<NetPacket> Deserialize(Socket client, int bufferLength = 100)
        {
            MemoryStream ms = new MemoryStream();
            int readingBytes;
            do
            {
                var Buffer = new byte[bufferLength];
                readingBytes = client.Receive(Buffer);
                if (readingBytes>0)
                {
                    ms.Write(Buffer, 0, readingBytes);
                }
            } while (client.Available > 0);
            NetPacket packet;
            try
            {
                BinaryFormatter formatter = new BinaryFormatter();
                ms.Position = 0;
                packet = formatter.Deserialize(ms) as NetPacket;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                Console.WriteLine("ClearPacket");
                return new NetPacket() { DataType = NetPacket.ObjectType.CLEAR };
            }
            ms.Dispose();
            return packet;
        }
        static public async Task<byte[]> Serialazie(NetPacket packet)
        {
            BinaryFormatter formatter = new BinaryFormatter();
            MemoryStream ms = new MemoryStream();
            formatter.Serialize(ms, packet);
            return ms.ToArray();
        }
    }
}
