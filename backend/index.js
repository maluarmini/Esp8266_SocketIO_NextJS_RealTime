const io = require("socket.io")(4000, {
    cors: {
        origin: '*',
    }
});

let info = 'Vitoria Baja Elétrica e Eletrônica';

io.on("connection", socket => {
    console.log("USUARIO: " + socket.id);

    socket.emit("info", info);

    socket.on("newinfo", (data) => {
        info = data.now;
        io.emit("info", info);
        console.log(info)
    });
})