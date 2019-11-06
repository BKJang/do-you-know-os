# Operating System Concepts

## Computer System은 세 가지 계층으로 나눌 수 있다.

- Hardware
- System
- Application

### System이나 Application이나 둘 다 Software지만 나눌 수 있는 이유는 뭘까?

- Military, Government Uses => General(일반적인) Purpose로 전환
- 각각의 기능을 하던 컴퓨터들에서 공통적으로 하드웨어를 제어하는 기능을 묶으면서 System이 구성된다.

### Application vs System vs Hardware

- Problem Solver vs Execution Environment vs Calculator
- User of Resources vs Resource Manager vs Resources

### System이 필요한 이유?

- `Hello World`를 한 줄로 짤 수 있는 이유
- Application Level에 사용편의성과 효율성을 제공
- Hardware Level을 보호(각각의 Application이 Hardware에 직접적인 영향을 미치지 않도록)
- JVM, Tomcat도 결국 Application Level

<br/>

## Hardware

- Turing Machine의 Head는 CPU, 띠는 RAM.
- 요즘 컴퓨터는 대부분 `튜링 완전하다`.

### Processor

Central Processing Unit(CPU)

#### ControlUnit: Head를 움직이는 역할
#### ALU: Turing Machine의 Head가 어디로 움질일지를 계산해주는 역할

- Arithmetic logic circuit (ALU)
- Store data in a set of registers (Control Unit)
- 하나의 레지스터에서 담을 수 있는 데이터는 32비트 컴퓨터는 32비트 64비트 컴퓨터는 64비트(R0-N, PC, SP, LR)
  - PC(Program Counter): 프로그램을 순차적으로 수행하는 레지스터
  - SP(Stack Pointer): Stack안에서 가장 마지막에 들어간 위치를 가리킨다.
  - LR(Link Register): function을 수행하고 돌아갈 위치를 저장해놓은 레지스터
- Read data and instructions from main memory(Control Unit)
  - 폰 노이만 아키텍쳐: Data와 Instruction을 다 같이 갖고 있는 구조(현재 대부분의 컴퓨터)
  - 하버드 아키텍쳐: Data와 Instrunction을 따로 갖는 구조


### Main Memory(RAM, Random Access Memory) - Primary Storage

- Volatile(휘발성)
- rewritable(Data의 overwrite)
- random-accessible
- Array of bits, bytes, kilobytes... and words
- Each byte has its own address
- 32비트 컴퓨터는 2^32비트 만큼을 쓸 수 있는데 이는 4GB이므로 메모리는 4GB만 쓸 수 있다.

### Processor와 Main Memory

- Fetch => Decode => Execution
- Fetch instruction from the address of memory written in PC.(Automatically)
- Decode and execute the instruction
- Update the value written in PC to point next address(Automatically)

### I/O => Storage - Secondary Storage

- Non-volatile, huge compared to Main memory
- slower than main memory
- rapidly emerging, evolving => HDD / SSD/ PRAM
  - PRAM : RAM + Storage

### Storage Device Hierarchy

Small but Fast => Huge but Slow

#### Primary

- Register
- Cache: 하버드 아키텍쳐를 사용(속도가 최우선이기 때문에 Data Cache와 Instrunction Cache를 분리)
- RAM

#### Secondary

- SSD
- HDD

#### Tertiary

- External Storage

### Processor와 I/O

#### Interrupts

- The way to synchronize I/O devices and CPU
- The signal for devices to inform CPU(e.g. finish its job)
- CPU must handle interrupts as soon as possible

#### Life of Interrupts

- An I/O device raises an iterrupt by sending signal to CPU(Interrupt Request, IRQ)
- Interrupt controller wihin CPU catches th signal
- CPU jumps to interrupt vector, dispatch and clear IRQ.(Interrupt Service Routine, ISR)

### System Bus

- Processor, I/O, Main Memory간의 데이터를 주고 받을 수 있도록 해주는 역할
- 데이터를 어떻게 주고 받을지를 정해놓은 인터페이스

<br/>

## How can we print out "Hello World" with single line?

1. CPU moves program from storage to main memory.
2. CPU commands a serial device to print out a chracter.
3. Serial Device는 문자를 출력하고 그 다음 문자를 CPU에게 요청.

### DMA(Dynamic Memory Access)

- DMA도 I/O기 떄문에 Interrupt가 발생한다.
- 유일하게 메모리에 직접 접근 가능한 아이
- 위의 2~3의 과정에서 overhead가 일어날 수 있는데 DMA를 통해 CPU에게 매번 가던 Interrupt를 DMA에서 수행한다.