package atv_ED;

import java.util.*;

public class SistemaVendas {

    private List<Venda> listaVendas = new ArrayList<>();

    // Adiciona uma venda ao sistema
    public void adicionarVenda(Venda venda) {
        listaVendas.add(venda);
    }

    // Laço 1 - Total de vendas por produto
    public Map<Produto, Integer> totalVendasPorProduto() {
        Map<Produto, Integer> totalVendasPorProduto = new HashMap<>();
        for (Venda venda : listaVendas) {
            Produto produto = venda.getProduto();
            int quantidade = venda.getQuantidade();
            totalVendasPorProduto.put(produto, totalVendasPorProduto.getOrDefault(produto, 0) + quantidade);
        }
        return totalVendasPorProduto;
    }

    // Laço 2 - Processamento contínuo das vendas
    public double calcularTotalVendas() {
        double total = 0;
        int index = 0;
        while (index < listaVendas.size()) {
            Venda venda = listaVendas.get(index);
            total += venda.getValorTotal();
            index++;
        }
        return total;
    }

    // Laço 3 - Relatório de clientes frequentes
    public Map<Cliente, Integer> clientesFrequentes() {
        Map<Cliente, Integer> clientesFrequentes = new HashMap<>();
        for (Venda venda : listaVendas) {
            Cliente cliente = venda.getCliente();
            clientesFrequentes.put(cliente, clientesFrequentes.getOrDefault(cliente, 0) + venda.getQuantidade());
        }
        return clientesFrequentes;
    }

    // Iteração - Comparar vendas entre períodos
    public double compararVendas(int inicio, int fim) {
        double total = 0;
        for (int i = inicio; i <= fim; i++) {
            total += listaVendas.get(i).getValorTotal();
        }
        return total;
    }

    // Função para imprimir o relatório de produtos vendidos
    public void imprimirRelatorioVendas() {
        Map<Produto, Integer> vendasPorProduto = totalVendasPorProduto();
        System.out.println("Relatório de Vendas por Produto:");
        for (Map.Entry<Produto, Integer> entry : vendasPorProduto.entrySet()) {
            System.out.println("Produto: " + entry.getKey().getNome() + ", Total Vendido: " + entry.getValue());
        }
    }

    // Função para imprimir o relatório de clientes frequentes
    public void imprimirRelatorioClientes() {
        Map<Cliente, Integer> frequenciaClientes = clientesFrequentes();
        System.out.println("\nRelatório de Clientes Frequentes:");
        for (Map.Entry<Cliente, Integer> entry : frequenciaClientes.entrySet()) {
            System.out.println("Cliente: " + entry.getKey().getNome() + ", Compras: " + entry.getValue());
        }
    }

    public static void main(String[] args) {
        SistemaVendas sistema = new SistemaVendas();

        // Criando produtos
        Produto produto1 = new Produto("Notebook", "Eletrônicos", 3000.00);
        Produto produto2 = new Produto("Celular", "Eletrônicos", 2000.00);
        Produto produto3 = new Produto("Câmera", "Eletrônicos", 1500.00);

        // Criando clientes
        Cliente cliente1 = new Cliente("Alice", "alice@example.com");
        Cliente cliente2 = new Cliente("Bob", "bob@example.com");
        Cliente cliente3 = new Cliente("Carlos", "carlos@example.com");

        // Adicionando vendas
        sistema.adicionarVenda(new Venda(produto1, cliente1, 2));
        sistema.adicionarVenda(new Venda(produto2, cliente1, 1));
        sistema.adicionarVenda(new Venda(produto3, cliente2, 3));
        sistema.adicionarVenda(new Venda(produto1, cliente3, 1));
        sistema.adicionarVenda(new Venda(produto3, cliente3, 2));

        // Exibindo relatórios
        sistema.imprimirRelatorioVendas();
        sistema.imprimirRelatorioClientes();

        // Calculando total de vendas
        double totalVendas = sistema.calcularTotalVendas();
        System.out.println("\nTotal de Vendas: R$ " + totalVendas);

        // Comparando vendas entre períodos
        double totalComparado = sistema.compararVendas(0, sistema.listaVendas.size() - 1);
        System.out.println("\nComparação de Vendas (Iterativa): R$ " + totalComparado);
    }
}
