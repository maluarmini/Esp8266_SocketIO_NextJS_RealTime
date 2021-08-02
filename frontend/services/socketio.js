import socketIOClient from "socket.io-client";

const socket = socketIOClient("localhost:4000");

export default socket;