<script setup>
import HelloWorld from './components/HelloWorld.vue'
</script>

<template>
  <div id="app">
    <SensorData />
  </div>
</template>

<script>
import SensorData from "./components/SensorData.vue";

export default {
  name: "App",
  components: {
    SensorData
  }
};
</script>

<style scoped></style>
