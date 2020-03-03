namespace Diagrams
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.setupToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.formulaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.FormulsList = new System.Windows.Forms.ToolStripComboBox();
            this.numericUpDownMinVal = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownMaxVal = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Scale = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.dXNumeric = new System.Windows.Forms.NumericUpDown();
            this.button1 = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinVal)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMaxVal)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Scale)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dXNumeric)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.setupToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // setupToolStripMenuItem
            // 
            this.setupToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.formulaToolStripMenuItem});
            this.setupToolStripMenuItem.Name = "setupToolStripMenuItem";
            this.setupToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
            this.setupToolStripMenuItem.Text = "Setup";
            // 
            // formulaToolStripMenuItem
            // 
            this.formulaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.FormulsList});
            this.formulaToolStripMenuItem.Name = "formulaToolStripMenuItem";
            this.formulaToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.formulaToolStripMenuItem.Text = "Formula";
            this.formulaToolStripMenuItem.Click += new System.EventHandler(this.formulaToolStripMenuItem_Click);
            // 
            // FormulsList
            // 
            this.FormulsList.Name = "FormulsList";
            this.FormulsList.Size = new System.Drawing.Size(121, 23);
            this.FormulsList.Click += new System.EventHandler(this.toolStripComboBox1_Click);
            // 
            // numericUpDownMinVal
            // 
            this.numericUpDownMinVal.Location = new System.Drawing.Point(205, 2);
            this.numericUpDownMinVal.Name = "numericUpDownMinVal";
            this.numericUpDownMinVal.Size = new System.Drawing.Size(120, 20);
            this.numericUpDownMinVal.TabIndex = 1;
            this.numericUpDownMinVal.ValueChanged += new System.EventHandler(this.numericUpDownMinVal_ValueChanged);
            // 
            // numericUpDownMaxVal
            // 
            this.numericUpDownMaxVal.Location = new System.Drawing.Point(378, 0);
            this.numericUpDownMaxVal.Name = "numericUpDownMaxVal";
            this.numericUpDownMaxVal.Size = new System.Drawing.Size(120, 20);
            this.numericUpDownMaxVal.TabIndex = 2;
            this.numericUpDownMaxVal.ValueChanged += new System.EventHandler(this.numericUpDownMaxVal_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(175, 4);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(24, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Min";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(345, 4);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(27, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Max";
            // 
            // Scale
            // 
            this.Scale.Location = new System.Drawing.Point(545, 0);
            this.Scale.Name = "Scale";
            this.Scale.Size = new System.Drawing.Size(120, 20);
            this.Scale.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(505, 2);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Scale";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(672, 2);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(20, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "dX";
            // 
            // dXNumeric
            // 
            this.dXNumeric.Location = new System.Drawing.Point(698, 2);
            this.dXNumeric.Name = "dXNumeric";
            this.dXNumeric.Size = new System.Drawing.Size(71, 20);
            this.dXNumeric.TabIndex = 8;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(58, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Draw";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dXNumeric);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Scale);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDownMaxVal);
            this.Controls.Add(this.numericUpDownMinVal);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinVal)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMaxVal)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Scale)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dXNumeric)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem setupToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem formulaToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox FormulsList;
        private System.Windows.Forms.NumericUpDown numericUpDownMinVal;
        private System.Windows.Forms.NumericUpDown numericUpDownMaxVal;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown Scale;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown dXNumeric;
        private System.Windows.Forms.Button button1;
    }
}

