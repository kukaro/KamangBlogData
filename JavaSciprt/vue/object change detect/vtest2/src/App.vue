<template>
    <div id="app">
        {{session}}<br>
        {{value}}<br>
        {{instance}}<br>
        <input type="button" value="session add" @click="onclicks"><br>
        <input type="button" value="value add" @click="onclickv"><br>
        <input type="button" value="instance add" @click="onclicki"><br>
    </div>
</template>

<script>
    import session from './js/session.js'

    let i = 0;
    let j = 10;
    let k = 5;
    let l = 7;

    export default {
        name: 'app',
        components: {},
        created() {
            console.log(this)
            this.instance = 0
        },
        data() {
            return {
                value: 0,
                session
            }
        },
        methods: {
            onclicks() {
                this.session[i++ + 'hi'] = j++ + 'hi'
            },
            onclickv() {
                this.value = k++
            },
            onclicki() {
                this.instance = l++
            }
        }
    }
</script>

<style>

</style>
