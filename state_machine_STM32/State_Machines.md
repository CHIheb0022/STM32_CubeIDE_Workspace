# State Machines

## 1. Event-Driven Programming

### Introduction
- Event-driven programming is crucial in understanding modern software development.
- Originated in graphical user interfaces (GUI) during the personal computer revolution.

### GUI Programming Background
- GUI introduced a paradigm shift from command-line systems.
- Unlike command-line interfaces, GUIs have multiple input sources (keyboard, mouse) and dynamic output locations.

### Characteristics of Event-Driven Programming
1. Multiple Inputs: GUIs introduce multiple input sources, requiring simultaneous input handling.
2. Dynamic Output Locations: Output locations are determined by user interactions.
3. Object Interaction: Mouse inputs require identification of objects on the screen.
4. Event Focus: Events drive the software, not sequential structure.

### Win32 API Example
- Original Win32 API demonstrates event-driven programming principles.
- Windows applications utilize event-driven architecture effectively.

### Event-Driven Systems
- Message Loop: Core of event-driven programming, processing messages from the event queue.
- Asynchronous Event Delivery: Events can be delivered even when the loop is processing other events.
- Run-to-Completion Processing: Event processing cannot be interrupted by other events.

### Role of the "Window Proc"
- Inversion of Control: Windows system calls the application, not vice versa.
- Default "Window Proc": Provides default behaviors for unhandled events, creating a consistent GUI experience.

### Contrasting with Sequential Programming
- Blocking and Responsiveness: Blocking calls in event-driven systems degrade responsiveness.
- Run-to-Completion Semantics: Blocking calls violate the expected event processing flow.
- Separation of Paradigms: Sequential programming and event-driven programming should be kept separate.

### Practical Implementation
- Use of timers instead of blocking calls for event-driven tasks.
- Example: LED blinking after keypresses using the Windows timer facility.
- Key Principle: Avoid blocking to maintain responsiveness and adhere to event-driven semantics.

### Conclusion
- Event-driven programming is essential for modern software development.
- Characteristics like no-blocking and asynchronous event delivery distinguish event-driven programs.
- Understanding event-driven principles is crucial for both GUI and embedded systems development.

## 2. Introduction to State Machines

### Introduction
- State machines are a fundamental concept in event-driven programming and active object design.
- They address the need to manage context and behavior transitions in event-driven systems.
- State machines offer a systematic approach to managing system behavior and context.

### Understanding Context Management
- Event-driven programming requires manual context management, leading to potential complexity.
- Manual context management often involves numerous flags and variables, resulting in spaghetti code.
- Example of a Visual Basic calculator illustrates the challenges of context management in event-driven systems.

### The Concept of State
- State represents the relevant history of past events, capturing only aspects influencing future behavior.
- States serve as equivalence classes of relevant histories, abstracting away irrelevant details.
- State machines formalize the concept of state, defining states and transitions based on event triggers.
- State machines offer graphical representations, such as state diagrams, to visualize behavior.

### Implementing State Machines
- State machines can be implemented in various ways, including manual coding and graphical modeling tools.
- QM modeling tool provides a convenient platform for designing state machines.
- Designing a state machine involves defining states, transitions, and initial conditions.
- State transitions are triggered by events and can include actions to be executed.

### Coding the State Machine
- State machine implementation starts with defining a state variable representing the current state.
- State transitions and event handling are coded using switch statements and cases.
- Mapping state machine elements to code involves a straightforward process.
- Coding experience emphasizes traceability between code and design, facilitating understanding and maintenance.

### Testing and Conclusion
- Testing the state machine code ensures proper functionality.
- State machine code should build without errors or warnings.
- The BlinkyButton example demonstrates the effectiveness of state machine implementation.
- Conclusion of the first lesson in the State Machine segment, with anticipation of future lessons on advanced state machine variants.

### Conclusion
- State machines offer a systematic approach to managing system behavior in event-driven programming.
- Understanding and implementing state machines provide benefits in terms of code organization, extensibility, and maintenance.
- Stay tuned for further exploration of state machine concepts in upcoming lessons.

## 3. Guard Conditions in State Machines

### Introduction
- State machines offer an optimal solution to systems reacting to events based on event type and past event history.
- "Guard conditions" enhance state machine flexibility by enabling event reactions based on runtime conditions.
- Choice pseudostates and guard conditions are key concepts in UML state machine notation.

### Using Choice Pseudostates and Guard Conditions
- Choice pseudostates are depicted as diamonds and allow transitions based on guard conditions.
- Guard conditions are boolean expressions evaluated at runtime, determining transition behavior.
- Complementary guards ("else") ensure transition when all other guards are false.

### Application Example - Time Bomb Controller
- Illustration of a time bomb controller using state machine with guard conditions.
- Designing states and transitions for the time bomb behavior.
- Implementing guard conditions to manage blinking behavior and explosion.

### Implementation and Code
- Manual coding of state machine using nested-switch statement technique.
- Translating choice pseudostates and guard conditions into IF statements in C code.
- Balancing the use of guard conditions for flexibility while avoiding spaghetti code.

### Testing and Conclusion
- Uploading code to the board and testing the time bomb behavior.
- Demonstrating flexibility by adjusting the blink counter and observing behavior.
- Emphasizing the importance of understanding when to use guard conditions.

### Next Steps
- Preparing for the next lesson on other variants of input-driven or polled state machines.
- Encouragement to subscribe and visit state-machine.com/quickstart for resources.

### Conclusion
- Understanding guard conditions enhances state machine flexibility.
- Mastery involves balancing design-time state definitions and runtime flexibility.
- Stay tuned for further exploration of state machine variants in upcoming lessons.

## 4. Introduction to different types of state machines used in software design.

### Historical Background
- Interest in state machines began in the 1950s with George Moore and Edward Mealy from Bell Telephone Company.
- They outlined the usefulness of state machines for designing digital circuits.
- State machines originated in hardware design but have influenced software design significantly.

### Combinational Circuits
- Digital circuits without internal state are called combinational circuits.
- Examples include OR-gates, AND-gates, XOR-gates, and inverters.
- Truth tables describe the behavior of combinational circuits.
- Limitations of combinational circuits led to the development of state machines for systems requiring memory.

### Mealy State Machine
- Named after Edward Mealy.
- Outputs depend on both the current state and inputs.
- State transitions are based on inputs, and outputs are a function of both state and input.

### Moore State Machine
- Named after George Moore.
- Outputs depend only on the current state.
- Requires more states compared to Mealy machines for equivalent functionality.

### State Machine Representation
- States represented as circles labeled with names.
- Transitions depicted with arrows labeled with inputs and outputs.
- Mealy and Moore state machines have slightly different representations.

### Synchronous vs. Asynchronous Circuits
- Synchronous circuits driven by a clock signal.
- Mealy and Moore focused predominantly on synchronous circuits.
- Asynchronous circuits lack a clock signal and can lead to race conditions.

### Software State Machines
- Different from event-driven state machines.
- Inputs drive state transitions based on logical expressions.
- Inputs represented by variables, akin to hardware bits.
- Transition conditions resemble guard conditions from previous lessons.

### Input-Driven State Machines
- Run "always" or "periodically" based on the environment.
- Execution frequency not always explicitly defined.
- Also known as controller or periodic state machines.
- Inputs are shared variables, potentially leading to race conditions.

### Implementation Challenges
- Asynchronous inputs can cause reliability issues.
- Buffering inputs improves robustness.
- Conversion to event-driven state machines is possible.

### Conclusion
- Reliability and robustness depend on the type of state machine and its environment.
- Input-driven state machines have advantages in certain scenarios.
- Understanding state machine implementations crucial for embedded systems programming.

# State Tables and Implementation

## Introduction
- State tables are an alternative implementation strategy for state machines.
- They provide a structured, data-driven approach to state transitions.
- This lesson explores state tables as a method for implementing state machines in embedded systems.

### State Tables
- State tables represent state transitions in a structured two-dimensional format.
- Cells in the table contain pairs of next-state and action for a given event in a given state.
- State tables provide a one-to-one correspondence with state diagrams.

### Implementing State Tables in C
- Use two-dimensional arrays in C to represent state tables.
- Define special constants (MAX_STATE and MAX_SIG) to track changes in state and event enumerations.
- Each cell in the array holds a pointer to a function (TimeBombAction) to handle state transitions.
- TimeBombAction function takes pointers to the state machine instance and the event parameters.
- State tables should be constant and placed in ROM to conserve RAM.
- Initialize the state table using C array initializer syntax.
- Define entry and exit actions for states, keeping the state machine's behavior intact.
- Use enums to specify return status types (TRAN_STATUS, HANDLED_STATUS, IGNORED_STATUS, INIT_STATUS) for action functions.

### Incorporating Entry and Exit Actions
- Entry and exit actions allow for cleaner organization of state-related actions.
- Entry actions are executed upon entering a state, while exit actions are executed upon leaving.
- Move repeated actions from transitions to entry/exit actions for better code organization.
- Convert the state machine from Mealy-type to Moore-type by associating actions with states rather than transitions.

### Implementing Entry and Exit Actions
- Define special ENTRY and EXIT signals in the event enumeration.
- Add entry and exit action functions for states in the state table.
- Modify the dispatch function to execute entry and exit actions on state transitions.
- Use status return types to determine if a transition occurred and execute appropriate actions.

### Advantages and Disadvantages of State Tables
- Advantages:
  - Highly structured and regular representation of state transitions.
  - Deterministic runtime performance.
- Disadvantages:
  - Fragmentation of code into many small action handlers.
  - Sparse tables with gaps, leading to potential inefficiency.
  - Discourages adding new states and events due to overhead in table modification.

### Conclusion
- State tables offer a structured approach to state machine implementation.
- While they have advantages, they also come with drawbacks that may affect code maintainability.
- Future lessons will explore alternative state machine implementation strategies.

---

# Hierarchical State Machines

## Definition
- Hierarchical state machines differ from traditional finite state machines by allowing states to contain other states.
- Implementation: Learn how to implement state hierarchy in C and understand the ease and complexity of different aspects.

## Extending TimeBomb Application
### Problem
- Address the limitations of traditional state machines by extending the TimeBomb application to include a defusing feature.
### Solution
- Implement a hierarchical state machine to handle the new functionality.

## Transition to Hierarchical State Machines
### Advantages
- Explore how hierarchical state machines eliminate repetitive code and simplify state transitions.
### Comparison
- Contrast hierarchical state machines with traditional approaches, highlighting the benefits.

## Moving to Professional Framework: QP/C
### Porting Exercise
- Transition from Micro-C-AO framework to the professional QP/C framework.
### Benefits
- Utilize QP/C's full support for hierarchical state machines and automatic code generation.
