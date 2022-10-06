library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity tb_sim is
--  Port ( );
end tb_sim;

architecture Behavioral of tb_sim is
COMPONENT fdc --'fdc' is the name of the module needed to be tested.
PORT ( 
    C : in STD_LOGIC;
    D_0 : in STD_LOGIC;
    D_1 : in STD_LOGIC;
    Q: out STD_LOGIC) ;
    END COMPONENT;
    
    signal D_0 : std_logic := '0'; 
    signal D_1 : std_logic := '0'; 
    signal C : std_logic := '0'; --declare outputs and initialize them 
    signal Q : std_logic := '0';
 begin
uut: fdc PORT MAP (
     C => C,
     D_0 => D_0,
     D_1=> D_1,
     Q => Q) ;
     
clock: process 
 begin
     C <= '0'; wait for 5 ns;
     C <= '1'; wait for 5 ns; 
 end process;
 
 tb : process
 begin
     D_0 <= '0'; D_1 <= '0'; wait for 50 ns;
     D_0 <= '1'; wait for 20 ns; 
     D_1 <= '1'; wait for 80 ns;
     D_1 <= '0'; wait for 40 ns; 
     D_1 <= '0'; wait for 40 ns;
     D_0 <= '1'; wait for 12 ns;
     D_1 <= '1'; wait for 17 ns;
     D_0 <= '0'; D_1 <= '0'; wait for 50 ns;
 end process;

end Behavioral;
