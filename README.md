# 자료구조 (Data Structures)

대학 자료구조 수업에서 작성한 C 과제 모음입니다. 원래 10여 개의 저장소에
흩어져 있던 것을 주제별로 하나로 정리했습니다. 한 학기 동안 기초 C 연습부터
그래프 알고리즘까지 어떤 순서로 배우고 구현했는지 따라가 볼 수 있습니다.

> 공부하는 분들이 참고하기 좋게 단계별로 정리해 두었습니다.
> 빌드 산출물(.exe, .obj 등)과 Visual Studio 프로젝트 파일은 제외하고
> 순수 소스(.c/.h)와 결과 스크린샷, 설명(README)만 담았습니다.
> 한글 주석은 모두 UTF-8로 변환했습니다.

## 목차

| 단계 | 주제 | 내용 |
|---|---|---|
| [`00-c-basics`](00-c-basics) | C 기초 연습 | 재귀(팩토리얼/거듭제곱), 소수, 다항식, 스택·연결리스트·큐 입문 (주차별) |
| [`03-tree-traversal`](03-tree-traversal) | 트리 순회 | 스택 기반 반복적 트리 순회 (ItrTreeTrv + Stack) |
| [`04-level-order-traversal`](04-level-order-traversal) | 레벨 순회 | 큐를 이용한 레벨 순서 순회 (LevelTraversal + Queue) |
| [`05-binary-search-tree`](05-binary-search-tree) | 이진 탐색 트리 | BST 삽입/탐색/삭제 |
| [`06-heap`](06-heap) | 힙 | 최대 힙 (배열 기반) + 트리 기반 버전 |
| [`07-heap-sort`](07-heap-sort) | 힙 정렬 | 힙을 이용한 정렬 |
| [`08-huffman`](08-huffman) | 허프만 코딩 | 허프만 트리 / 압축 |
| [`09-dfs-bfs`](09-dfs-bfs) | DFS / BFS | 그래프 깊이·너비 우선 탐색 |
| [`10-prim-mst`](10-prim-mst) | 프림 MST | 프림 최소 신장 트리 |
| [`11-find-mst`](11-find-mst) | MST 찾기 | 최소 신장 트리 구하기 |
| [`12-dijkstra`](12-dijkstra) | 다익스트라 | 최단 경로 |
| [`13-sorting`](13-sorting) | 정렬 비교 | 기본 정렬 / 셸 / 합병 / 퀵 |
| [`14-searching`](14-searching) | 탐색 비교 | 순차·이진 탐색 비교 / 보간 탐색 |
| [`15-avl`](15-avl) | AVL 트리 | AVL 균형 트리 비교 |

폴더 번호는 대략적인 학습 순서입니다.

## 빌드

각 폴더의 `.c` 파일은 표준 C로 작성되어 있습니다. 예:

```bash
cd 05-binary-search-tree
gcc *.c -o bst && ./bst
```
