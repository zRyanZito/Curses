import { TipoTransacao } from "../types/TransationType.js";
import { Transacao } from "../types/Transation.js";
import { GrupoTransacao } from "./TransationGroup.js";

let saldo: number = JSON.parse(localStorage.getItem("saldo")) || 0;
const transacoes: Transacao[] = JSON.parse(localStorage.getItem("transacoes"), (key: string, value: string) => {
    if(key === "data") return new Date(value);

    return value;
}) || [];

function debitar(valor: number) : void{
    if(valor <= 0) throw new Error("O valor deve ser maior que zero!");
    if(valor > saldo) throw new Error("Saldo Insuficiente");
    saldo -= valor;

    localStorage.setItem("saldo", saldo.toString());
}

function depositar(valor: number) : void{
    if(valor <= 0) throw new Error("O valor deve ser maior que zero!");
    saldo += valor;

    localStorage.setItem("saldo", saldo.toString());
}

const Conta = {
    getSaldo(){
        return saldo;
    },

    getDataAcesso(): Date {
        return new Date();
    },

    getGrupoTransacoes(): GrupoTransacao[] {
        const gruposTransacoes: GrupoTransacao[] = [];
        const listaTransacoes: Transacao[] = structuredClone(transacoes);
        const transacoesOrdenadas: Transacao[] = listaTransacoes.sort((t1, t2) => t2.data.getTime() - t1.data.getTime());
        let labelAtualGrupoTransacao: string = "";

        for(let transacao of transacoesOrdenadas){
            let labelGrupoTransacao: string = transacao.data.toLocaleDateString("pt-BR", { month: "long", year: "numeric"} );

            if( labelAtualGrupoTransacao !== labelGrupoTransacao){
                labelAtualGrupoTransacao = labelGrupoTransacao;

                gruposTransacoes.push({
                    label: labelGrupoTransacao,
                    transacoes: []
                })
            }
            gruposTransacoes.at(-1).transacoes.push(transacao);
        }

        return gruposTransacoes;
    },

    registrarTransacao(novaTransacao: Transacao): void{
        if(novaTransacao.tipo === TipoTransacao.DEPOSITO){
            depositar(novaTransacao.valor);
        }
        else if(novaTransacao.tipo === TipoTransacao.TRANSFERENCIA || novaTransacao.tipo === TipoTransacao.PAGAMENTO_BOLETO){
            debitar(novaTransacao.valor);
            novaTransacao.valor *= -1;
        }
        else{
            throw new Error("Tipo de transação inválido!");
        }

        transacoes.push(novaTransacao);

        localStorage.setItem("transacoes", JSON.stringify(transacoes));
    }
}

export default Conta;