/* store.js */
import Vue from 'vue'
import Vuex from 'vuex'
import axios from 'axios'

Vue.use(Vuex);

export default new Vuex.Store({
    state: {
        count: 0,
        weight: 2,
        random: 0,
    },
    mutations: {
        increment(state) {
            state.count++;
        },
        decrement(state) {
            state.count--;
        },
        successGenerateRandomNumber(state, payload){
            state.random = payload.num;
        },
        failGenerateRandomNumber(/*state, payload*/){
            console.log('ERROR!');
        }
    },
    getters:{
        count(state, getters){
            return Math.pow(state.count, getters.weight);
        },
        weight(state, /*getters*/){
            return state.weight;
        },
        random(state, /*getters*/){
            return state.random;
        }
    },
    actions:{
        generateRandomNumber({commit, /*state*/}, /*payload*/) {
            axios.get(`http://localhost:4321/`)
                .then((res) => {
                    commit('successGenerateRandomNumber', res.data);
                })
                .catch((res) => {
                    commit('failGenerateRandomNumber', res);
                });
        }
    }
})
