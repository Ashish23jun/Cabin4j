const nodemailer = require("nodemailer")

const mail = async () => {
    let testAccount = await nodemailer.createTestAccount();
    const config = nodemailer.createTransport({
        host: "smtp.gmail.com",
    port: 587,
    secure: false,
    auth: {
      user:'pandey.k.ashish.86@gmail.com', 
      pass: 'luelrrgxzmvfyixl',
    },
    });

    const sendemailnow = await config.sendMail({
        from: 'pandey.k.ashish.86@gmail.com',
    to: "sales@cabin4j.com",
    subject: "Challenges Completed", 
    text: "Hello world?",
    html: "<h2>Name:<h2><p>Ashish Pandey</p><h3>Email</h3><p>pandey.k.ashish.86@gmail.com</p><h3>Mobile Number</h3><p>9120245703</p><p><b>BRANCH:</b>IT<br><b>YEAR:</b>Second<br><b>DEPARTMENT:</b>IT department<br><b>ROLL No.:</b>2100290130046<br></p>", 
    attachments:  [
        {
            filename:'ashish.jpg',
            path:__dirname+'/Ashish.HEIC'
        },
    ]
    });
    console.log("Message sent: %s", sendemailnow.messageId);
  
  console.log("Preview URL: %s", nodemailer.getTestMessageUrl(sendemailnow));
};

mail().catch((e)=> console.log(e));
