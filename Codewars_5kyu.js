/*-Memoized Fibonacci-*/

var fibonacci = function(n, valores = []) {
    if (n < 2) return n;
  
    if(valores[n])
      return valores[n]
  
    valores[n] = fibonacci(n-1, valores) + fibonacci(n-2, valores);
    return valores[n];
}

/*-Going to zero or to infinity?-*/

function going(n) { // Best practice
    var res = 1.0;
    var inter = 1.0;
    for (var i = n; i >=2; i--) {
        inter = inter * (1 / i);
        res += inter;
    }
    return Math.floor(res * Math.pow(10, 6)) / Math.pow(10, 6);
}

function going(n) {
  let result = 1;
  let suma = 0;
  for(let i = n ; i > 0 ; i--){
    let factorialValue = factorial(i);
    if(i === n){
      result /= factorialValue;
    }
    suma += factorialValue;
  }
  
  let cantidadDespuesDeLaComa = Math.min(n - 1, 6);
  let stringNumero = (result*suma).toString().split('.');
  
  if(stringNumero[1]){
    stringNumero[1] = stringNumero[1].substring(0, cantidadDespuesDeLaComa);
  }
  return parseFloat(stringNumero.join('.'));
}

function factorial(n, values = []){
  if(n === 1) return values[1] = 1;
  if(values[n]) return values[n];
  
  let valorToReturn = values[n] = n * factorial(n-1, values);
  return valorToReturn;
}

/*-Closest and Smallest-*/
// TO DO

function  closest(strng) {
  console.log(strng)
  if(strng === ""){
    return [];
  }
  const arrayAux = strng.split(" ")
  
  const array = arrayAux.map((x, index) => {    
    return {
      number_weight : Array.from(x).reduce((acc, res) => Number(acc) + Number(res) ,0),
      index_strng : index,
      original_corresponding : Number(x)
    }
  });
  
  array.forEach((x, index) => {
    if(array[index + 1]){
      x['diff_next'] = Math.abs(array[index + 1].number_weight - x.number_weight);
    }else{
      if(array[index - 1]){
        x['diff_next'] = array[index - 1].diff_next;
      }else{
        x['diff_next'] = 0;
      }
    }
  })
  array.sort((a,b) => (a.diff_next + a.number_weight) - (b.number_weight + b.diff_next));
  console.log(array)
}

