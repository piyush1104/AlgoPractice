const getConversion(adj, sourceMetric, targetMetric) => {
  if(dp[targetMetric] === undefined) {
    return undefined
  }
  if(dp[sourceMetric])
  if(adj[sourceMetric][targetMetric] !== undefined) {
    return adj[sourceMetric][targetMetric]
  }
  let keys = Object.keys(adj[sourceMetric])
  for(let i=0; i< keys.length; i++) {
    let conversion = getConversion(adj, keys[i], targetMetric)
    if(conversion === undefined) {
      continue
    }
    dp[sourceMetric] = adj[sourceMetric][keys[i]] * conversion
    return adj[sourceMetric][keys[i]] * conversion
  }

}

const solve = (metrics, queries) => {
  let adj = {}
  for(let i=0; i<metrics.length; i++) {
    let firstMetric = metrics[i][0]
    let secondMetric = metrics[i][1]
    let metricValue = metrics[i][2]
    if(adj[firstMetric] !== undefined) {
      adj[firstMetric] = {[secondMetric]: metricValue}
    } else {
      adj[firstMetric][secondMetric] = metricValue
    }
    if(adj[secondMetric] !== undefined) {
      adj[secondMetric] = {[firstMetric]: (1 / metricValue)}
  } else {
    adj[secondMetric][firstMetric] = 1 / metricValue
  }
  for(let i=0; i<queries.length; i++) {
    let query = queries[i]
    let sourceMetric = query[0]
    let targetMetric = query[1]
    let sourceValue = query[2]
    if(adj[sourceMetric][targetMetric] !== undefined) {
      console.log(sourceValue * adj[sourceMetric][targetMetric])
      continue
    }
    let dp = {}
    dp[sourceMetric] = -1
    let conversion = getConversion(adj, sourceMetric, targetMetric, dp)
    if(conversion === undefined) {
      console.log('Not found')
    }else {
      console.log(sourceValue * get)
    }
  }
}



m -> cm

dm -> mm

kg -> g

let metrices = [['m', 'cm', 100], ['kg', 'g', 1000], ['dm', 'mm', 10], ['cm', 'dm']]

let queries = [['m', 'mm'], ['g', 'kg']]
