// src/firebaseConfig.js
import { initializeApp } from 'firebase/app';
import { getFirestore } from 'firebase/firestore';

// Your Firebase Config Object
const firebaseConfig = {
  apiKey: "AIzaSyBGOR4qhJmn_rKkQmXQ0F-UR3LzACncLC0",
  authDomain: "iot-project-firebase-admin.firebaseapp.com",
  projectId: "iot-project-firebase-admin",
  storageBucket: "iot-project-firebase-admin.appspot.com",
  messagingSenderId: "482207957760",
  appId: "1:482207957760:web:a1be6a8982db10981d29e5"
};

// Initialize Firebase app
const app = initializeApp(firebaseConfig);

// Get Firestore instance
const db = getFirestore(app);

export { db };
