#include<bits/stdc++.h>

#define leftn n*2
#define rightn (n*2)+1
#define INF 10e9
#define ll long long

using namespace std;

struct SegmentTree {


    vector<ll> ST;
    vector<ll> lazy;
    size_t arr_size;

    SegmentTree(vector<ll> &arr) {

        arr_size = arr.size();

        ST.resize(4*arr_size);
        lazy.resize(4*arr_size);
        // pasamos el arreglo, el nodo que empieza, el 
        // primer valor posible del arreglo y el ultimo posible
        build(arr, 1, 0, arr_size-1);
    }


    void build(vector<ll> &arr, ll n, ll start, ll end) {

        // llegamos a un rango x ejemplo [4:4]
        if (start == end)
            // es nodo tamaño 1, no se puede hacer ninguna operacion
            ST[n] = arr[start];
        else {
            ll middle = (start+end)/2;

            // construye primero los nodos de la izquierda
            build(arr, leftn, start, middle);
            // luego construye todos los de la derecha
            build(arr, rightn, middle+1, end);

            // la suma
            ST[n] = min(ST[leftn], ST[rightn]);
        }
        
    }

    ll query(ll a, ll b) {
        return query(1, 0, arr_size-1, a, b);
    }

    ll query(ll n, ll start, ll end, ll i, ll j) {

        if (j < start or i > end) {
            return INF;
        }
        
        if (i <= start and end <= j)
            return ST[n];

        ll mid = (start+end)/2;

        // es imposible que haya un nodo derecho
        if (j <= mid)
            // retorno el nodo izquierdo
            return query(leftn, start, mid, i, j); // es lo mismo que abajo
        // es imposible que haya uno izquierdo
        if (i > mid)
            return query(rightn, mid+1, end, i, j); // es la misma query que el nodo de abajo
       
        ll node_left  = query(leftn, start, mid, i, j);
        ll node_right = query(rightn, mid+1, end, i, j);

        return min(node_left, node_right);
    }

    void update(ll pos, ll value, vector<ll> &arr) {
        update(1, pos, 0, arr_size-1, value, arr);
    }

    void update(ll n, ll index, ll start, ll end, ll value, vector<ll> &arr) {
        if (start == end) {
            ST[n] = value;
            arr[index] = value;
        } else {
            ll middle = (start+end)/2;
            
            if (index <= middle)
                update(leftn, index, start, middle, value, arr);
            else
                update(rightn, index, middle+1, end, value, arr);

            ST[n] = min(ST[leftn], ST[rightn]);
        }
    }

};

int main() {
    ll n, q;
    scanf("%lld%lld", &n, &q);

    vector<ll> s(n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", &s[i]);

    SegmentTree ST(s);
    while(q--) {
        ll kind;
        scanf("%lld", &kind);
        // update
        if (kind == 1) {
            ll index, val;
            scanf("%lld%lld", &index, &val);
            index--;
            ST.update(index, val, s);
        } else {
            ll from, to;
            scanf("%lld%lld", &from, &to);
            from--; to--;
            printf("%lld\n", ST.query(from ,to));
        }

    }

    return 0;
}