library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

--The VHDL language uses '--' to indicate a comment.--
entity fdc is 
    Port (D_0, D_1: in STD_LOGIC;
    C : in STD_LOGIC;
    Q : out STD_LOGIC);
end fdc;

architecture Behavioral of fdc is

signal x_0, x_1 : STD_LogIC;
    
begin
    process (C)
    begin
        if rising_edge(C) then
        X_0 <= D_0;
        X_1 <= D_1;
    end if;
end process;
    process (C)
    begin
        if rising_edge(C) then
        Q<= X_0 and X_1;
        end if;
    end process;
end Behavioral;
