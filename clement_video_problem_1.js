// the question is here - https://www.youtube.com/watch?v=rw4s4M3hFfs

const blocks = [
  {
    gym: false,
    school: true,
    store: false,
  },
  {
    gym: true,
    school: false,
    store: false,
  },
  {
    gym: true,
    school: true,
    store: false,
  },
  {
    gym: false,
    school: true,
    store: false,
  },
  {
    gym: false,
    school: true,
    store: true,
  },
]

const reqs = ['gym', 'school', 'store']

const INT_MAX = 2 ** 31 - 1

function solve(blocks, reqs) {
  let n = blocks.length
  let a = []
  for (let i = 0; i < reqs.length; i++) {
    let block = blocks[0]
    let building = reqs[i]
    let value = block[building] ? 0 : INT_MAX
    a.push(value)
  }
  // return a
  let scoresL = [a]
  for (let j = 1; j < n; j++) {
    a = []
    for (let i = 0; i < reqs.length; i++) {
      let block = blocks[j]
      let building = reqs[i]
      let value
      if (block[building]) {
        value = 0
      } else {
        value = scoresL[j - 1][i] === INT_MAX ? INT_MAX : scoresL[j - 1][i] + 1
      }
      a.push(value)
    }
    scoresL.push(a)
  }

  console.log(scoresL)

  a = []
  for (let i = 0; i < reqs.length; i++) {
    let block = blocks[n - 1]
    let building = reqs[i]
    let value = block[building] ? 0 : INT_MAX
    a.push(value)
  }

  let scoresR = [a]

  for (let j = n - 2; j >= 0; j--) {
    a = []
    for (let i = 0; i < reqs.length; i++) {
      let block = blocks[j]
      let building = reqs[i]
      let value
      if (block[building]) {
        value = 0
      } else {
        value =
          scoresR[n - j - 2][i] === INT_MAX
            ? INT_MAX
            : scoresR[n - j - 2][i] + 1
      }
      a.push(value)
    }
    scoresR.push(a)
  }

  scoresR.reverse()

  console.log(scoresR)

  let scores = []
  for (let j = 0; j < n; j++) {
    a = []
    for (let i = 0; i < reqs.length; i++) {
      a.push(Math.min(scoresL[j][i], scoresR[j][i]))
    }
    scores.push(a)
  }

  let min = INT_MAX

  for (let j = 0; j < n; j++) {
    let blockScore = Math.max(...scores[j])
    min = Math.min(min, blockScore)
  }

  return min
}

console.log(solve(blocks, reqs))
