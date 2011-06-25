package main

import (
  "fmt"
  "rand"
)

const (
  // Probability of a increasing the height of a node, higher value means
  // higher probability.
  HIGHER_PROB= 0.5
  MAX_HEIGHT = 32
)

type Node struct {
  height int
  value int
  next []*Node
}

type SkipList struct {
  head *Node
  maxHeight int
}

func NewNode(height int, value int) *Node {
  node := new(Node)
  node.next = make([]*Node, height)
  node.height = height
  node.value = value
  return node
}

func NewList() *SkipList {
  var list *SkipList = new(SkipList)
  // First node is a dummy node with pointers at all levels.
  dummy := NewNode(MAX_HEIGHT, -1)
  list.head = dummy
  list.maxHeight = 0
  return list
}

func Insert(list *SkipList, value int) {
  // Increase the height. The higher it is, the less likely it is to increase
  // in height.
  height := 1
  for r := rand.Float32(); r < HIGHER_PROB && height <= MAX_HEIGHT;
      r = rand.Float32() {
    height++
  }

  // Create a node with this height and insert it into the list.
  if list.maxHeight < height {
    list.maxHeight = height
  }

  node := NewNode(height, value)
  cur := list.head
  for i := list.maxHeight - 1; i >= 0; i-- {
    for ; cur.next[i] != nil; cur = cur.next[i] {
      if (cur.next[i].value > value) {
        break
      }
    }
    // Link up skippy!
    if i < height {
      node.next[i] = cur.next[i]
      cur.next[i] = node
    }
  }
}

/*
 * Delete one value if it exists.
 */
func Remove(list *SkipList, value int) bool {
  cur := list.head
  for i := list.maxHeight - 1; i >= 0; i-- {
    for ; cur.next[i] != nil; cur = cur.next[i] {
      if (cur.next[i].value > value) {
        break
      } else if (cur.next[i].value == value) {
        // Value found at the next link at this level, update the link and
        // move down to the next level.
        toDelete := cur.next[i]
        cur.next[i] = toDelete.next[i]
        break
      }
    }
  }
  return false
}

func Contains(list *SkipList, value int) bool {
  cur := list.head
  for i := list.maxHeight - 1; i >= 0; i-- {
    for ; cur.next[i] != nil; cur = cur.next[i] {
      if (cur.next[i].value > value) {
        break
      } else if (cur.next[i].value == value) {
        return true
      }
    }
  }
  return false
}

func Walk(list SkipList, cb func(int)) {
  for cur := list.head.next[0]; cur != nil; cur = cur.next[0] {
    cb(cur.value)
  }
}


func AssertTrue(val bool, msg string) {
  if (!val) {
    panic(msg)
  }
}

func main() {
  list := *NewList()
  printlnInt := func(i int) { fmt.Println(i) }
  Insert(&list, 3)
  Insert(&list, 4)
  Insert(&list, 1)
  Insert(&list, 8)
  Insert(&list, 2)
  Insert(&list, 10)
  Insert(&list, 9)
  Insert(&list, 4)
  Insert(&list, 12)
  Insert(&list, 3)
  Walk(list, printlnInt)

  fmt.Println()
  Remove(&list, 1)
  Remove(&list, 3)
  Remove(&list, 3)
  Remove(&list, 4)
  Walk(list, printlnInt)
  AssertTrue(Contains(&list, 100) == false, "fail")
  AssertTrue(Contains(&list, 4) == true, "fail")
  AssertTrue(Contains(&list, 9) == true, "fail")
  AssertTrue(Contains(&list, 1) == false, "fail")

}
