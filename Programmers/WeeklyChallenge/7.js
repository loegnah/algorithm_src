function solution(enter, leave) {
  let answer = new Array(enter.length + 1);
  let beforeEnterLeaveCnt = new Array(enter.length + 1);
  let leaveCnt = 0;
  let iEnter = 0;

  beforeEnterLeaveCnt.fill(-1);

  for (let curLeave of leave) {
    if (beforeEnterLeaveCnt[curLeave] === -1) {
      let breakFlag = false;
      while (!breakFlag) {
        if (enter[iEnter] === curLeave) breakFlag = true;
        beforeEnterLeaveCnt[enter[iEnter]] = leaveCnt;
        iEnter++;
      }
    }
    answer[curLeave] = iEnter - 1 - beforeEnterLeaveCnt[curLeave];
    leaveCnt++;
  }

  answer = answer.slice(1);
  return answer;
}

const enters = [
  [1, 3, 2],
  [1, 4, 2, 3],
  [3, 2, 1],
  [3, 2, 1],
  [1, 4, 2, 3],
];
const leaves = [
  [1, 2, 3],
  [2, 1, 3, 4],
  [2, 1, 3],
  [1, 3, 2],
  [2, 1, 4, 3],
];

for (let i = 0; i < enters.length; i++) {
  console.log(solution(enters[i], leaves[i]));
}
