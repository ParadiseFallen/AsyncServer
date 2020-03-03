using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.ListBox;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            BindingList<object> a = new BindingList<object>();
            a.Add(

                new { Name = "a",Val = 3}

                );


            ListBox lb = new ListBox();
            SelectedObjectCollection selectedObjectCollection = new SelectedObjectCollection(lb);

            a = new BindingList<dynamic>(Users.Except(selectedObjectCollection.Cast<List<object>>()).ToList()) ;
            
            a.ToList();
        }

        private void c(object sender, EventArgs e)
        {
            MessageBox.Show("noone help you");
        }
    }
}
