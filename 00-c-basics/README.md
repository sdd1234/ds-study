# 00. C 기초 연습

자료구조 본격 진입 전, **주차별로** 작성한 C 기초 연습 모음입니다.
파일 이름은 `월-일_주제.c` 형식이라 위에서 아래로 **학습한 순서대로** 정렬됩니다.
같은 주제를 점점 발전시켜 가는 흐름(스택: 전역배열 → 구조체 → 수식 계산)이 보입니다.

## 파일별 설명 (시간순)

### 3월 — 기본 문법 · 재귀
| 파일 | 내용 |
|---|---|
| [`03-14_prime.c`](03-14_prime.c) | **소수**: 2부터 n까지 돌며 각 수가 소수인지 판별하고 출력/합산. 나눗셈 반복으로 약수 존재 여부 확인. |
| [`03-14_factorial.c`](03-14_factorial.c) | **팩토리얼**: `factorial_iter`(반복)와 `factorial_rec`(재귀)를 둘 다 구현해 비교. `n! = n×(n-1)!` |
| [`03-19_factorial.c`](03-19_factorial.c) | 팩토리얼 재작성본 (int 인자 버전). 같은 개념을 다시 정리. |
| [`03-19_factorial-v2.c`](03-19_factorial-v2.c) | 팩토리얼 또 다른 버전. 반복/재귀 비교 연습 반복. |
| [`03-19_power.c`](03-19_power.c) | **거듭제곱**: `power_iter` vs `power_rec`. `nʲ = n×nʲ⁻¹`. 선형 재귀의 대표 예. |

> 재귀의 핵심은 **종료 조건(base case)** + **자기 호출**. 팩토리얼·거듭제곱처럼
> 단순 선형 재귀는 반복문으로도 1:1 변환된다는 걸 직접 확인합니다.

### 4월 초 — 다항식
| 파일 | 내용 |
|---|---|
| [`04-02_polynomial-array.c`](04-02_polynomial-array.c) | **다항식 곱셈 (계수 배열 방식)**: 차수 = 인덱스로 보고 계수를 배열에 담아 곱셈. `multiply`/`print`. |
| [`04-08_polynomial-sparse.c`](04-08_polynomial-sparse.c) | **다항식 곱셈 (항 범위 방식)**: 항들을 start~end 인덱스 구간으로 표현하고 `poly_multiply`로 곱함. 희소 다항식에 가까운 표현. |
| [`04-08_polynomial-sparse-v2.c`](04-08_polynomial-sparse-v2.c) | 위 방식의 개선/재작성본. |

### 4월 중·하 — 스택 (점점 발전)
| 파일 | 내용 |
|---|---|
| [`04-14_stack-global.c`](04-14_stack-global.c) | **가장 기초 스택**: 전역 배열 + `top` 변수. `push`/`pop`/`is_full`/`is_empty`. ADT 개념 입문. |
| [`04-17_stack-struct.c`](04-17_stack-struct.c) | **구조체 스택**: `StackType`으로 캡슐화하고 `peek` 추가. 여러 스택을 동시에 다룰 수 있게 됨. |
| [`04-22_stack-postfix.c`](04-22_stack-postfix.c) | **후위 표기식 계산** (`eval`): 스택을 실제로 활용 — 피연산자는 push, 연산자 만나면 두 개 pop해 계산. |
| [`04-24_stack-infix.c`](04-24_stack-infix.c) | **중위 → 후위 변환 + 계산**: `prec`(연산자 우선순위), `infix_to_postfix`, `eval`까지. 스택 응용의 완성형. |

> 스택 4개를 순서대로 보면 "ADT를 어떻게 점점 추상화하고, 어디에 써먹는가"가 한눈에 들어옵니다.

### 5월 — 큐 · 리스트
| 파일 | 내용 |
|---|---|
| [`05-06_queue-circular.c`](05-06_queue-circular.c) | **원형 큐 (배열 기반)**: `front`/`rear`를 모듈러로 돌려 배열을 원형으로 재사용. `enqueue`/`dequeue`. |
| [`05-20_arraylist.c`](05-20_arraylist.c) | **배열 리스트**: `ArrayListType`. 위치 지정 삽입(`insert`), 앞/뒤 삽입, `get_entry`로 임의 접근(O(1)). |
| [`05-22_linkedlist.c`](05-22_linkedlist.c) | **단일 연결 리스트**: `listNode`(데이터+링크). 위치 기반 삽입/삭제. 임의 접근은 O(n)이지만 삽입/삭제 O(1). |
| [`05-27_arraylist-v2.c`](05-27_arraylist-v2.c) | 배열 리스트 재작성본. 노드 개념과 배열 표현을 함께 정리. |

> 배열 리스트 vs 연결 리스트 — **임의 접근(배열 유리) vs 삽입·삭제(연결 유리)** 의 트레이드오프를 직접 비교.

### 6월 — 연결 리스트 변형
| 파일 | 내용 |
|---|---|
| [`06-03_circular-list.c`](06-03_circular-list.c) | **원형 연결 리스트**: `tail` 포인터 하나로 앞/뒤 삽입·삭제. 마지막 노드가 첫 노드를 가리켜 순환. |
| [`06-10_doubly-list.c`](06-10_doubly-list.c) | **이중 연결 리스트**: `DListNode`(앞/뒤 링크). `dinsert`/`ddelete`. 양방향 순회 가능. |

### 9월 — 트리 입문 (자료구조 수업 연결)
| 파일 | 내용 |
|---|---|
| [`09-10_tree-traversal.c`](09-10_tree-traversal.c) | **트리 순회 종합**: 배열 표현 트리(`ArrayPreOrder`/`InOrder`/`PostOrder`)와 포인터 트리(`LinkPreOrder`/…)를 모두 구현해 전위·중위·후위 순회 비교. → [`../03-tree-traversal`](../03-tree-traversal)로 이어짐. |

---

> 이 폴더는 같은 개념을 여러 번 다시 짠 **연습본**이라 파일마다 완성도가 다릅니다.
> 정제된 완성형은 상위 단계 폴더(`03~`)에서 볼 수 있습니다.
