<h1>Core War: The hunter</h1><br/>
<h2>An inntegrated vm and asembler program</h2><br/>

<h1>Table of contents</h1>
<ul>
  <li>Description</li>
  <li>Resource Overview</li>
  <li>The VM </li>
  <li>The ASM </li>
  <li>The Player </li>
</ul>
<h1 id="Description">Description</h1>
<p>
  The project is split into two distinct parts, namely the Virtual machine and the Assembler. The Vitrual machine is 
  designed to take 4 players in the form of assembled .cor files and run them on a memory board. The goal here is to build
  a player that stays alive the longest.
  The Assembler takes in a player, written in a pseudo-assembly language (a ".s" file) and generates a vm understandable .cor file
  with the byte code of the player.
</p>
<h1 id="Resources">Resource Overview</h1>
<p>
  For the purposes of this project one is given an "op.h" and "opinfo.c" file which describe the artifacts to be used within the
  program. In these files the list of available commands to the players is defined, The board (memory size) is defined, as well
  as a few other rules of engagment.
</p>
<h1 id = "VM">The VM</h1>
<p>
</p>
<h1 id = "ASM">The ASM</h1>
<p>
  To compile this segment of the project, one should enter the asm directory and type:
  Make
  To then run the compiler and generate your players ".cor" file type:
  ./asm ...
  where "..." is a list of all your ".s" files (note multiple players can be compiled at once)
  
</p>
