import Conta from "../types/Account.js";
import { FormatoData } from "../types/DateFormate.js";
import { GrupoTransacao } from "../types/TransationGroup.js";
import { formatarData, formatarMoeda } from "../utils/Formatters.js";

const elementoRegistroTransacoesExtrato: HTMLElement = document.querySelector(".extrato .registro-transacoes");

renderizarExtrato();
function renderizarExtrato(): void{
    const gruposTransacoes:GrupoTransacao[] = Conta.getGrupoTransacoes();

    elementoRegistroTransacoesExtrato.innerHTML = "";

    let htmlRegistroTransacoes: string = "";

    for(let grupoTransacao of gruposTransacoes){
        let htmlTransacaoItem: string = "";
        for(let transacao of grupoTransacao.transacoes){
            htmlTransacaoItem += `
                <div class="transacao-item">
                    <div class="transacao-info">
                        <span class="tipo">${transacao.tipo}</span>
                        <strong class="valor">${formatarMoeda(transacao.valor)}</strong>
                    </div>
                    <time class="data">${formatarData(transacao.data, FormatoData.DIA_MES)}</time>
                </div>
            `
        }

        htmlRegistroTransacoes += `
            <div class="transacoes-group">
                <strong class="mes-group">${grupoTransacao.label}</strong>
                ${htmlTransacaoItem}
            </div>
        `;
    }


    if(htmlRegistroTransacoes === ""){
        htmlRegistroTransacoes = `
            <div>Nenhuma transação encontrada</div>
        `
    }

    elementoRegistroTransacoesExtrato.innerHTML = htmlRegistroTransacoes;
}

const extratoComponent = {
    atualizar(): void{
        renderizarExtrato();
    }
}

export default extratoComponent