import static org.junit.Assert.*;

import org.junit.Test;

public class PilhaTest {

	@Test
	public void testarPilha() {
		Pilha pilha = new Pilha();

        pilha.push(50);
        pilha.push(450);
        pilha.push(200);
        pilha.push(10);
        System.out.println(pilha.top());
        
        assertNotNull(pilha);
        assertEquals(10, pilha.top());
        
        pilha.pop();
        System.out.println(pilha.top());
        
        assertNotNull(pilha);
        assertEquals(200, pilha.top());
        
        
	}
}
