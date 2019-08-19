namespace CS1._6自制修改器
{
    partial class frmCS
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmCS));
            this.btnMoney = new System.Windows.Forms.Button();
            this.timMoney = new System.Windows.Forms.Timer(this.components);
            this.btnBlood = new System.Windows.Forms.Button();
            this.timBlood = new System.Windows.Forms.Timer(this.components);
            this.timShoot = new System.Windows.Forms.Timer(this.components);
            this.btnShoot = new System.Windows.Forms.Button();
            this.timBoom = new System.Windows.Forms.Timer(this.components);
            this.btnBoom = new System.Windows.Forms.Button();
            this.btnDefence = new System.Windows.Forms.Button();
            this.timDefence = new System.Windows.Forms.Timer(this.components);
            this.btnGame = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnMoney
            // 
            this.btnMoney.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnMoney.Enabled = false;
            this.btnMoney.Location = new System.Drawing.Point(12, 153);
            this.btnMoney.Name = "btnMoney";
            this.btnMoney.Size = new System.Drawing.Size(94, 23);
            this.btnMoney.TabIndex = 0;
            this.btnMoney.Text = "金钱无限";
            this.btnMoney.UseVisualStyleBackColor = false;
            this.btnMoney.Click += new System.EventHandler(this.btnMoney_Click);
            // 
            // timMoney
            // 
            this.timMoney.Tick += new System.EventHandler(this.timMoney_Tick);
            // 
            // btnBlood
            // 
            this.btnBlood.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnBlood.Enabled = false;
            this.btnBlood.Location = new System.Drawing.Point(12, 12);
            this.btnBlood.Name = "btnBlood";
            this.btnBlood.Size = new System.Drawing.Size(94, 23);
            this.btnBlood.TabIndex = 1;
            this.btnBlood.Text = "血量不减";
            this.btnBlood.UseVisualStyleBackColor = false;
            this.btnBlood.Click += new System.EventHandler(this.btnBlood_Click);
            // 
            // timBlood
            // 
            this.timBlood.Tick += new System.EventHandler(this.timBlood_Tick);
            // 
            // timShoot
            // 
            this.timShoot.Tick += new System.EventHandler(this.timShoot_Tick);
            // 
            // btnShoot
            // 
            this.btnShoot.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnShoot.Enabled = false;
            this.btnShoot.Location = new System.Drawing.Point(14, 106);
            this.btnShoot.Name = "btnShoot";
            this.btnShoot.Size = new System.Drawing.Size(94, 23);
            this.btnShoot.TabIndex = 1;
            this.btnShoot.Text = "子弹无限";
            this.btnShoot.UseVisualStyleBackColor = false;
            this.btnShoot.Click += new System.EventHandler(this.btnShoot_Click);
            // 
            // timBoom
            // 
            this.timBoom.Tick += new System.EventHandler(this.timBoom_Tick);
            // 
            // btnBoom
            // 
            this.btnBoom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnBoom.Enabled = false;
            this.btnBoom.ForeColor = System.Drawing.Color.DarkRed;
            this.btnBoom.Location = new System.Drawing.Point(12, 200);
            this.btnBoom.Name = "btnBoom";
            this.btnBoom.Size = new System.Drawing.Size(94, 23);
            this.btnBoom.TabIndex = 2;
            this.btnBoom.Text = "高爆手雷无限";
            this.btnBoom.UseVisualStyleBackColor = false;
            this.btnBoom.Click += new System.EventHandler(this.btnBoom_Click);
            // 
            // btnDefence
            // 
            this.btnDefence.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnDefence.Enabled = false;
            this.btnDefence.Location = new System.Drawing.Point(12, 59);
            this.btnDefence.Name = "btnDefence";
            this.btnDefence.Size = new System.Drawing.Size(94, 23);
            this.btnDefence.TabIndex = 3;
            this.btnDefence.Text = "护甲不减";
            this.btnDefence.UseVisualStyleBackColor = false;
            this.btnDefence.Click += new System.EventHandler(this.btnDefence_Click);
            // 
            // timDefence
            // 
            this.timDefence.Tick += new System.EventHandler(this.timDefence_Tick);
            // 
            // btnGame
            // 
            this.btnGame.BackColor = System.Drawing.Color.Aqua;
            this.btnGame.Location = new System.Drawing.Point(181, 252);
            this.btnGame.Name = "btnGame";
            this.btnGame.Size = new System.Drawing.Size(94, 58);
            this.btnGame.TabIndex = 4;
            this.btnGame.Text = "启动";
            this.btnGame.UseVisualStyleBackColor = false;
            this.btnGame.Click += new System.EventHandler(this.btnGame_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Location = new System.Drawing.Point(222, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 5;
            this.label1.Text = "秋雨制作";
            // 
            // frmCS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(284, 322);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnGame);
            this.Controls.Add(this.btnDefence);
            this.Controls.Add(this.btnBoom);
            this.Controls.Add(this.btnShoot);
            this.Controls.Add(this.btnBlood);
            this.Controls.Add(this.btnMoney);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "frmCS";
            this.Text = "CS 1.6修改器";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnMoney;
        private System.Windows.Forms.Timer timMoney;
        private System.Windows.Forms.Button btnBlood;
        private System.Windows.Forms.Timer timBlood;
        private System.Windows.Forms.Timer timShoot;
        private System.Windows.Forms.Button btnShoot;
        private System.Windows.Forms.Timer timBoom;
        private System.Windows.Forms.Button btnBoom;
        private System.Windows.Forms.Button btnDefence;
        private System.Windows.Forms.Timer timDefence;
        private System.Windows.Forms.Button btnGame;
        private System.Windows.Forms.Label label1;
    }
}

