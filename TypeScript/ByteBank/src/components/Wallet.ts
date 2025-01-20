import { formatarData, formatarMoeda } from "../utils/Formatters.js";
import { FormatoData } from "../types/DateFormate.js";
import Conta from "../types/Account.js";

const elementoSaldo = document.querySelector(".saldo-valor .valor") as HTMLElement;
const elementoData = document.querySelector(".block-saldo time") as HTMLElement;

if (elementoData != null) elementoData.textContent = formatarData(Conta.getDataAcesso(), FormatoData.DIA_SEMANA_DIA_MES_ANO);

setSaldo();
function setSaldo() : void{
    if (elementoSaldo != null) elementoSaldo.textContent = formatarMoeda(Conta.getSaldo());
}

const SaldoComponent = {
    atualizar(){
        setSaldo();
    }
}

export default SaldoComponent;