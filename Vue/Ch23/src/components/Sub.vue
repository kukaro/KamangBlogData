<!--Sub.vue-->
<template>
    <div class="sub">
        methods - count: {{methodsCount()}}<br>
        <input type="button" value="증가" @click="countMethods++">
        <input type="button" value="감소" @click="countMethods--"><br>
        computed - count: {{computedCount}}<br>
        <input type="button" value="증가" @click="countComputed++">
        <input type="button" value="감소" @click="countComputed--">
    </div>
</template>

<script>

    export default {
        name: 'Sub',
        props: {
            value:{}
        },
        watch: {

        },
        computed: {
            computedCount(){
                console.log('computed');
                return this.value;
            }
        },
        data() {
            return {
                countMethods: 0,
                countComputed: 0,
            }
        },
        created: function () {
        },
        methods: {
            methodsCount(){
                console.log('methods');
                return this.countMethods;
            }
        },
    }
</script>

<style scoped>
    .person {
        padding: 10px;
        background-color: skyblue;
    }
</style>
