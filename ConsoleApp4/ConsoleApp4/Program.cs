using System;
using System.Threading;
using System.Collections.Generic;
using System.Data.Sql;
using System.Linq;

namespace ConsoleApp4
{
    class Program
    {
        static void Ma2in(String[] args)
        {
            AppDomain adCallingThreadDomain = Thread.GetDomain();

            AppDomain d2 = AppDomain.CreateDomain("Second");
            d2.ExecuteAssembly("ConsoleApp4.exe");
            //String callingDomainName = adCallingThreadDomain.FriendlyName;
            //Console.WriteLine("Default appdomain's friendly name={0}", callingDomainName);

            //String exeAssembly = Assembly.GetEntryAssembly().FullName;
            //Console.WriteLine("Main assembly = {0}", exeAssembly);

            //AppDomain ad2 = null;
            //Console.WriteLine("{0} Demo #1", Environment.NewLine);
            //ad2 = AppDomain.CreateDomain("AD #2", null, null);
            //MarshalByRefType mbrt = null;
            //mbrt = (MarshalByRefType)ad2.CreateInstanceAndUnwrap("ConsoleApp4", "ConsoleApp4.MarshalByRefType");
            //Console.WriteLine("Type = {0}",mbrt.GetType());
            //Console.WriteLine("IS Proxy={0}",RemotingServices.IsTransparentProxy(mbrt));
            //Console.Write(Environment.NewLine);
            //mbrt.SomeMethod();
            //AppDomain.Unload(ad2);
            //try
            //{
            //    mbrt.SomeMethod();
            //}
            //catch (AppDomainUnloadedException)
            //{
            //    Console.WriteLine("Failed Call");
            //}
            //Console.WriteLine("{0} Demo #2",Environment.NewLine);
            //ad2 = AppDomain.CreateDomain("AD #2", null, null);
            //mbrt = (MarshalByRefType)ad2.CreateInstanceAndUnwrap(exeAssembly, "ConsoleApp4.MarshalByRefType");
            //MarshalByValType mbvt = mbrt.MethodWithReturn();
            //Console.WriteLine("IS Proxy {0}",RemotingServices.IsTransparentProxy(mbvt));
            //AppDomain.Unload(ad2);
            //Console.WriteLine(mbvt.ToString());
        }

        static void Main(String[] args)
        {
           public static string connectString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=data.accdb;";
        List<String> vybork = new List<String>
            {
                "BMW","Audi","Rolls-Royce","Lexus","Nissan","Renault","Mercedes-Benz","Opel","Volkswagen","Mazda","Bugatti","Lamborghini","Dacia"
            };
        List<Car> cars = new List<Car>
            {
                new Car("BMW",330),
                new Car("Audi",255),
                new Car("Rolls-Royce",600),
                new Car("Lexus",335),
                new Car("Nissan",170)
            };
        //var vyborka = from car in cars group car by car.Power into grouped select grouped;
        //foreach (var item in vyborka)
        //{
        //    Console.WriteLine(item.ToString());
        //}

        var res = from car in cars
                  orderby car.Power descending
                  select car;
            foreach (var item in res)
            {
                Console.WriteLine(item.ToString());
                Console.WriteLine(item.ToString());
            }
}







    //var res = from item in vybork where item.Length < 10 && item.StartsWith("R") select item;
    //foreach (var item in res)
    //{
    //    Console.WriteLine("Item = {0}", item);
    //}




    class Car
{
    string name;
    int power;
    public Car(string n, int p)
    {
        name = n;
        power = p;
    }
    public override string ToString()
    {
        return string.Format("{0} {1}", name, power);
    }
    public string Name
    {
        get => name;
    }
    public int Power
    {
        get => power;
    }
}


class MarshalByRefType : MarshalByRefObject
{
    public MarshalByRefType()
    {
        Console.WriteLine("{0} ctor running in {1}", this.GetType().ToString(), Thread.GetDomain().FriendlyName);
    }
    public void SomeMethod()
    {
        Console.WriteLine("Executing in " + Thread.GetDomain().FriendlyName);
    }

    public MarshalByValType MethodWithReturn()
    {
        Console.WriteLine("Executing in " + Thread.GetDomain().FriendlyName);
        MarshalByValType t = new MarshalByValType();
        return t;

    }
}
[Serializable]
class MarshalByValType : Object
{
    private DateTime m_creationTime = DateTime.Now;
    public MarshalByValType()
    {
        Console.WriteLine(Environment.NewLine);
        Console.WriteLine("{0} ctor running in {1},created on {2:D}", this.GetType().ToString(), Thread.GetDomain().FriendlyName, m_creationTime.ToLongDateString());
    }
}
}
