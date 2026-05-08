const express = require("express");

const mongoose = require("mongoose");

const path = require("path");

const app = express();

const PORT = 3000;

/* Middleware */

app.use(express.json());

app.use(express.static(__dirname));

/* MongoDB Connection */

mongoose.connect(process.env.MONGO_URL, {

    useNewUrlParser: true,
    useUnifiedTopology: true

})
.then(() => {

    console.log("MongoDB Connected");

})
.catch((err) => {

    console.log(err);

});

/* Schema */

const userSchema = new mongoose.Schema({

    email: String,
    password: String
});

/* Model */

const User = mongoose.model("User", userSchema);

/* Login Route */

app.post("/login", async (req, res) => {

    try {

        const { email, password } = req.body;

        const user = await User.findOne({

            email,
            password
        });

        if(user) {

            res.json({
                message: "Login Successful"
            });

        } else {

            res.json({
                message: "Invalid Credentials"
            });
        }

    } catch(error) {

        res.status(500).json({
            message: "Server Error"
        });
    }
});

/* Create Demo User */

app.get("/create-user", async (req, res) => {

    try {

        const existingUser = await User.findOne({

            email: "test@gmail.com"
        });

        if(existingUser) {

            return res.send("User already exists");
        }

        const newUser = new User({

            email: "test@gmail.com",

            password: "1234"
        });

        await newUser.save();

        res.send("Demo user created");

    } catch(error) {

        res.status(500).send("Error");
    }
});

/* Start Server */

app.listen(PORT, () => {

    console.log(`Server running on port ${PORT}`);
});