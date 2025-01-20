import { Transacao } from "./Transation.js";

export type GrupoTransacao = {
    label: string;
    transacoes: Transacao[];
}