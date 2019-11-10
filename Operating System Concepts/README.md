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

<br/>

## Single-Processor System

- Core : Execute instruction and stroe data locally
- With other components to support the core
- Processor became bottleneck

## Multi-Processor System

- Multiple processors with single core for each
- AMP(Asymmetric Multi Processing)
  - 각각의 프로세서는 다른 역할
- SMP(Symmetric Multi Processing)
  - 각각의 프로세서가 모든 역할을 분산
  - 일반적으로 SMP방식을 채택
- To increase throughput N times
- However, the throughput actually is "<=N" times

## Multi-Core System

- Multiple cores within single processor
- Fast communication and low power consumption(멀티 프로세서 시스템은 시스템 버스를 통해 통신하지만 멀티 코어 시스템은 내부적으로 일어나기 때문에 상대적으로 성능이 더 좋다)
- Still have some problem, but currently standard

## NUMA(Non-Uniform Memory Access)

- Multiple processors with local memory for each (프로세서별로 메모리가 다 따로 존재)
- 코어는 여러 개지만 메모리는 하나다보니 모든 코어에서 하나의 메모리에 접근하게 된다. 그러다보니 시스템 버스에 병목현상이 일어난다.
- Latency on remote access <= This is hot
- Memory간의 동시성 처리는 Core 간의 통신으로 해결
- 물리적으로 Memory가 여러 개

## Clustered System

- Multiple Computers with single storage
- Asymmetric Clustering
  - 하나의 컴퓨터가 죽는다면 모니터링만 하던 컴퓨터가 그 역할을 수행
- Symmetric Clustering
  - 모든 컴퓨터가 모니터링을 진행하고 가장 여유 있는 컴퓨터가 죽은 컴퓨터의 역할을 수행
- High availability service
- Need to reprogram application for parallelization

## Today's Computer System

- Personal Computing
- Embedded mobile computing
- Client-server computing
- Peer to peer computing
- Cloud Computing
- Real-time embedded computing

<br/>

## System

### Life of Operating System (Boot Sequence)

- 최소 1개의 메모리와 1개의 Core
- Boot Loader를 통해 Memory에 OS가 올라감

1. Initialize primary CPU and other components in processor
2. Set up system components to operates computer
3. Wake secondary CPUs and initialize devices (ex. DMA 초기화)
4. Execute system programs(daemon) and become idle
5. OS Waiting for any events to occur

### Execution of Application Software

1. Program initially is stored in storage device
2. Load progream into main memory
3. Execute code of program line by line

### Process

1. Active instance of program in execution
2. Use computer resources to perform its tasks
3. What if process becomes idle?

### Multiprogramming

- 하나의 프로세스가 놀고 있는 동안에는 다른 프로세스를 실행
- Keep users stisfied and reduce CPU idle time
- Need techniques for resources to be shared

### Multitasking

- 여러 개의 프로세스를 놀고 동작하고를 반복
- 시분할 운영체제
- Switch processes periodically and frequently
- Provide faster response time to users
- Use timer to maintain control over CPUs
  - timer
    - Use clock signal and tick counter to get percise time
    - Periodic - Generate interrupts on every N times
    - One shot - Generate interrupts after N ticks

### Multimode Operation

- Hardware support for various execution modes
- At least two level - Kernel mode & user mode
- Limit every hardware access and some instructions
- mode bit를 통해 User Mode와 Kernel Mode를 따로 관리

### Scenario of Multimode Operation

- OS booting scene: Kernel Mode
- After booting: User Mode
- Any events given to Kernel: Kernel Mode
- User Mode => Kernel Mode로 오는 경우를 Exception(Trap)
  - Unauthorized hardware access from application
  - Interrupts raised by any hardware devices
  - Service requests from application to kernel
  - 결국 System Call(Software Interrupt, SWI)도 Exception을 통해서 일어나는 것
- Kernal Mode와 User Mode가 서로 넘어갈 때 Context Switching이 일어난다.

### Today's Operating System(POSIX Standard를 통해 개발)

- Multics(1964 / MIT, AT&T, GE)
- UNIX(1969 / Dennis Ritchie) - With C Language
- BSD(1977 / CSRG @ UC Berkeley)
- LINUX(1991 / Linus Trovalds) - And ... Git in 2005
- Darwin(2000 / Apple)
- Windows NT(1993 / Microsoft)