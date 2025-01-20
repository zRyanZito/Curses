import SaldoComponent from "./Wallet.js";
import Conta from "../types/Account.js";
import extratoComponent from "./Extract.js";
const elementoFormulario = document.querySelector(".block-nova-transacao form");
elementoFormulario.addEventListener("submit", function (event) {
    event.preventDefault();
    try {
        if (!elementoFormulario.checkValidity()) {
            alert("Preencha todos os campos corretamente!");
            return;
        }
        const inputTipoTransasao = elementoFormulario.querySelector("#tipoTransacao");
        const inputTipoValor = elementoFormulario.querySelector("#valor");
        const inputTipoData = elementoFormulario.querySelector("#data");
        let inputTransasao = inputTipoTransasao.value;
        let inputValor = inputTipoValor.valueAsNumber;
        let inputData = new Date(inputTipoData.value + " 00:00:00");
        const novaTransacao = {
            tipo: inputTransasao,
            valor: inputValor,
            data: inputData
        };
        Conta.registrarTransacao(novaTransacao);
        SaldoComponent.atualizar();
        extratoComponent.atualizar();
        elementoFormulario.reset();
    }
    catch (error) {
        alert(error.message);
    }
});
