/**   Memory leaks
 *
   double* p = new double[27];
    // …
    p = new double[42];
    // …
    delete[] p;
}

// 1st array (of 27 doubles) leaked




delete pi;	// deallocate an individual object
delete pc;	// deallocate an individual object
delete[ ] pd;	// deallocate an array
*/
