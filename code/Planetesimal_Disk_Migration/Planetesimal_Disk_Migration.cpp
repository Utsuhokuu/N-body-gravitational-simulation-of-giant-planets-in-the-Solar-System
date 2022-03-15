#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "rebound.h"

void heartbeat(struct reb_simulation* r);
double E0;

int reb_collision_resolve_merge_pass_through(struct reb_simulation* const r, struct reb_collision c);






int reb_collision_resolve_merge_pass_through(struct reb_simulation* const r, struct reb_collision c) {
    
}

void heartbeat(struct reb_simulation* r) {
    if (reb_output_check(r, 100.*r->dt)) { // The function reb_output_check will return 1 current time every 100 time units.
        // relative energy error
        double E = reb_tools_energy(r); // ?
        double relE = fabs((E-E0)/E0); // ?

        // get orbital elements
        struct reb_particle p = r->particles[2];
        struct reb_particle star = r->particles[0];
        struct reb_orbit o = reb_tools_particle_to_orbit(r->G, p, star);

        printf("a2=%f, dE=%e, N=%d\n", o.a, relE, r->N);
    }
}