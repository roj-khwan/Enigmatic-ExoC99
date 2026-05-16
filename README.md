TODO !!!! make a doc!
run with this!
```bash
cmake --build build --config Release
```

## Minimax simple Architecture
```txt
minimaxstate -> {
    ismax // for minimac
    depth
    alpha // floor
    beta // ceiling
}
absolute -> {
    first_state,
    maxdepth,
}
interface -> {
    get all move
    create copy
    destroy copy
    play move
    evaluate state score
}
bestmove(absolute, state, minimaxstate, intrerface) {
    bestmove = lowest number
    declare best move

    get all moves
    for each move {
        create copy of state, minimax state
        update minimaxstate
        
        play move on copy
        
        get score on state using minimax

        destroy copy of the state
        if (score is more than best score) {
            bestmove = move
            bestscore = scorew

            if (bestscore is more than minimaxstate.alpha){
                minimaxstate.alpha = bestscore
            }
        }
    }

    return bestmove
}

minimax(absolute, state, minimaxstate, interface) {
    evaluate state score
    if score is not zero
        return score
    else if (maxdepth is equal to minimaxstate.depth)
        return 0

    declare bestscore
    if (is maxing)
        bestscore = lowest number
    else
        bestscore = highest number

    get all moves
    for each move {
        create copy of state
        play move on copy

        get score on state using minimax

        destroy copy of the state
        if (is maxing) {
            update bestscore if score is more than bestscore

            update alpha if bestscore is more than alpha
        } else {
            update bestscore if score is less than bestscore

            update beta is bestscore is lower than beta
        }

        break if alpha is more than beta
    }

    return bestscore
}
```