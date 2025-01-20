import { Transacao } from "./Transation";
import { GrupoTransacao } from "./TransationGroup";
import { TipoTransacao } from "./TransationType";

export class Conta{
    nome: string;
    saldo: number = JSON.parse(localStorage.getItem("saldo")) || 0;
    transacoes: Transacao[] = JSON.parse(localStorage.getItem("transacoes"), (key: string, value: any) => {
        if (key === "data"){
            return new Date(value);
        }
        return value;
    }) || [];

    constructor(nome: string){
        this.nome = nome;
    }

    getGrupoTransacoes(): GrupoTransacao[] {
        const gruposTransacoes: GrupoTransacao[] = [];
        const listaTransacoes: Transacao[] = structuredClone(this.transacoes);
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
    }

    getSaldo(){
        return this.saldo;
    }

    getDataAcesso(){
        return new Date();
    }

    registrarTransacao(novaTransacao: Transacao): void{
            if(novaTransacao.tipo === TipoTransacao.DEPOSITO){
                this.depositar(novaTransacao.valor);
            }
            else if(novaTransacao.tipo === TipoTransacao.TRANSFERENCIA || novaTransacao.tipo === TipoTransacao.PAGAMENTO_BOLETO){
                this.debitar(novaTransacao.valor);
                novaTransacao.valor *= -1;
            }
            else{
                throw new Error("Tipo de transação inválido!");
            }
    
            this.transacoes.push(novaTransacao);
    
            localStorage.setItem("transacoes", JSON.stringify(this.transacoes));
        }

        debitar(valor: number): void{
            if(valor <= 0) throw new Error("O valor deve ser maior que zero!");
            if(valor > this.saldo) throw new Error("Saldo Insuficiente");
            this.saldo -= valor;
        
            localStorage.setItem("saldo", this.saldo.toString());
        }
        
        depositar(valor: number): void{
            if(valor <= 0) throw new Error("O valor deve ser maior que zero!");
            this.saldo += valor;
        
            localStorage.setItem("saldo", this.saldo.toString());
        }
}

const conta = new Conta("Joana");

export default conta;