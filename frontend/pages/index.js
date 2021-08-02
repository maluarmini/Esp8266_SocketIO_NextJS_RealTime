import { useEffect, useState } from 'react';
import socket from '../services/socketio';
import styles from '../styles/Home.module.scss';

export default function Home() {
  const [info, setInfo] = useState();

  useEffect(() => {
    socket.on('info', (data) => {
      setInfo(data)
    })
  },[])

  return (
      <>
      <div className={styles.header}>
        <img className={styles.image} src="/VB.png"/>
        <p className={styles.title}>Vitória Baja - Elétrica e Eletrônica</p>
      </div>
      <h1>{info}</h1>
      </>
  )
}
