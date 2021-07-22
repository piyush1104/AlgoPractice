const solve = scores => {
  let aggScores = {}
  for (let i = 0; i < scores.length; i++) {
    let name = scores[i][0]
    let score = parseInt(scores[i][1])
    if (aggScores[name] !== undefined) {
      let avgScore = aggScores[name]['avgScore']
      let count = aggScores[name]['count']
      avgScore = (avgScore * count + score) / (count + 1)
      aggScores[name] = { avgScore, count: count + 1 }
    } else {
      aggScores[name] = { avgScore: score, count: 1 }
    }
  }
  let keys = Object.keys(aggScores)
  let max = aggScores[keys[0]].avgScore
  for (let i = 0; i < keys.length; i++) {
    if (max < aggScores[keys[i]].avgScore) {
      max = aggScores[keys[i]].avgScore
    }
  }
  return max
}

let scores = [
  ['jerry', '65'],
  ['bob', '91'],
  ['jerry', '23'],
  ['Eric', '83'],
]

// console.log(solve(scores))

let obj = {
  a: 3,
  change: () => {
    console.log(this.a)
    this.a = 4
  },
  change2: function () {
    console.log(this.a)
    this.a = 5
  },
}

obj.change()
console.log(obj.a)
// console.log(global.a)

obj.change2()
console.log(obj.a)
// console.log(global.a)
