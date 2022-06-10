// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut v = Vec::new();
        list_to_Vec(head, &mut v);
        let mut root: Option<Box<ListNode>> = None;
        for &i in v.iter() {
            root = Some(Box::new(ListNode { val: i, next: root }))
        }
        root
    }
}

pub fn list_to_Vec(head: Option<Box<ListNode>>, v: &mut Vec<i32>) {
    match head {
        None => (),
        Some(b) => {
            v.push(b.val);
            list_to_Vec(b.next, v);
        }
    }
}
