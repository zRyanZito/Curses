import { Transacao } from "../types/Transation.js";
import SaldoComponent from "./Wallet.js";
import Conta from "../types/Account.js";
import extratoComponent from "./Extract.js";

const elementoFormulario = document.querySelector(".block-nova-transacao form") as HTMLFormElement;

elementoFormulario.addEventListener("submit", function(event) {
    event.preventDefault();
    
    try {
        if(!elementoFormulario.checkValidity()) {
            alert("Preencha todos os campos corretamente!");
            return;
        }

        const inputTipoTransasao = elementoFormulario.querySelector("#tipoTransacao") as HTMLSelectElement;
        const inputTipoValor = elementoFormulario.querySelector("#valor") as HTMLInputElement;
        const inputTipoData = elementoFormulario.querySelector("#data") as HTMLInputElement;

        let inputTransasao: string = inputTipoTransasao.value;
        let inputValor: number = inputTipoValor.valueAsNumber;
        let inputData: Date = new Date(inputTipoData.value + " 00:00:00");

        const novaTransacao: Transacao = {
            tipo: inputTransasao,
            valor: inputValor,
            data: inputData
        };

        Conta.registrarTransacao(novaTransacao);
        SaldoComponent.atualizar();
        extratoComponent.atualizar();
        elementoFormulario.reset();
    } catch (error) {
        alert(error.message);
    }
});