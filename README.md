lem_in
42 algorithm project for finding best ways in the graph

# Usage
~~~~
./lem-in < map
~~~~
# Map description
you have to use it without the "<-" comments
~~~~
15              <-  Number of ants.
3 10 50         <-  Room name, followed by its x-y coordinates.
##start         <-  Special room "start", the source of our flow.
start 20 30
##end           <-  The other special room, our target.
end 25 90
4 10 70
1 20 50
2 20 70
5 30 50
6 30 70
start-1          <-  "start" room is connected to the "1" room.
3-4              <-  "3" is connected to "4", and so on.
2-4
1-5
6-5
end-6
1-2
2-end
3-start
~~~~
