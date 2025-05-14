<template>
    <div>
        <h1>Sensor Data Readings</h1>
        <ul>
            <li v-for="data in sensorData" :key="data.id">
                🌡 Temperature: {{ data.temperature }}°C, 💧 Humidity: {{ data.humidity }}%
            </li>
        </ul>
    </div>
</template>

<script>
import { db } from '../firebaseConfig'; // adjust path as needed
import { collection, getDocs } from 'firebase/firestore';

export default {
    data() {
        return {
            sensorData: [],
        };
    },
    created() {
        this.fetchData();
    },
    methods: {
        async fetchData() {
            try {
                const querySnapshot = await getDocs(collection(db, 'sensorData'));
                this.sensorData = querySnapshot.docs.map(doc => ({
                    id: doc.id,
                    ...doc.data(),
                }));
            } catch (error) {
                console.error("🔥 Error fetching sensor data:", error);
            }
        },
    },
};
</script>

<style scoped>
ul {
    list-style-type: none;
    padding: 0;
}

li {
    margin: 8px 0;
    font-family: Arial, sans-serif;
}
</style>
