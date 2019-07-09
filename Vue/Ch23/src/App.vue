<!--App.vue-->
<template>
    <div id="app">
        <Sub :value="value"></Sub>
        <input type="button" value="클릭" @click="value++">
    </div>
</template>

<script>
    import Sub from './components/Sub'

    export default {
        name: 'App',
        components: {
            Sub
        },
        data() {
            return {
                value:0
            }
        },
        methods:{

        }
    }
</script>

<style scoped>

</style>
