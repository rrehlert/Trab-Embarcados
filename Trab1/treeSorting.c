
#include <stdio.h>
#include <stdlib.h>
// Part of Cosmos by OpenGenus Foundation
struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;
void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;
void main( )
{
    struct btreenode *bt ;
    int arr[1000] = { 52, 928, 703, 893, 715, 564, 671, 31, 75, 471, 732, 801,
438, 960, 681, 819, 95, 547, 799, 353, 261, 245, 497, 281,
78, 46, 971, 970, 741, 274, 574, 779, 683, 826, 66, 472,
875, 407, 446, 126, 417, 456, 353, 550, 767, 260, 151, 563,
215, 489, 966, 900, 143, 263, 593, 392, 369, 226, 414, 830,
488, 507, 797, 668, 184, 874, 924, 448, 929, 911, 277, 998,
174, 658, 984, 510, 78, 190, 466, 879, 107, 877, 798, 452,
26, 662, 906, 593, 661, 636, 552, 161, 615, 548, 856, 167,
105, 211, 228, 49, 944, 211, 105, 654, 306, 236, 181, 776,
646, 746, 775, 459, 678, 721, 430, 768, 866, 613, 387, 120,
872, 769, 560, 119, 471, 736, 194, 60, 824, 166, 33, 249,
424, 881, 992, 691, 968, 757, 5, 970, 412, 685, 590, 977,
630, 576, 889, 580, 948, 297, 482, 213, 984, 72, 560, 524,
233, 220, 383, 869, 989, 613, 759, 807, 577, 76, 152, 400,
36, 108, 377, 98, 285, 787, 216, 880, 204, 725, 394, 181,
319, 269, 859, 332, 498, 992, 617, 385, 492, 923, 13, 614,
146, 991, 80, 742, 94, 124, 524, 655, 477, 606, 267, 695,
662, 675, 464, 428, 200, 129, 848, 750, 139, 273, 925, 607,
642, 922, 420, 842, 920, 233, 37, 315, 631, 269, 579, 94,
180, 848, 629, 496, 550, 512, 824, 502, 130, 819, 855, 557,
620, 512, 722, 743, 251, 924, 233, 703, 944, 213, 336, 255,
651, 366, 576, 422, 528, 652, 860, 307, 888, 140, 100, 309,
39, 925, 105, 574, 753, 324, 823, 668, 551, 201, 666, 383,
967, 373, 596, 123, 906, 961, 884, 529, 604, 828, 321, 849,
569, 356, 736, 876, 567, 868, 233, 278, 32, 826, 368, 134,
674, 824, 981, 365, 434, 474, 305, 906, 178, 589, 813, 890,
923, 984, 886, 207, 133, 598, 151, 196, 824, 522, 703, 269,
777, 34, 365, 895, 940, 761, 497, 628, 928, 183, 502, 221,
370, 540, 489, 85, 650, 762, 152, 958, 49, 230, 311, 532,
791, 830, 500, 568, 651, 291, 484, 303, 387, 859, 949, 145,
355, 396, 239, 981, 481, 71, 638, 247, 634, 433, 667, 570,
958, 547, 236, 64, 73, 599, 732, 559, 354, 667, 36, 201,
76, 991, 900, 60, 582, 906, 265, 370, 302, 359, 689, 989,
518, 853, 946, 262, 260, 338, 614, 1000, 813, 826, 964, 684,
285, 447, 47, 725, 292, 852, 289, 463, 165, 404, 804, 36,
570, 646, 980, 766, 413, 948, 678, 750, 474, 390, 390, 392,
674, 591, 555, 807, 943, 245, 298, 445, 947, 662, 210, 891,
978, 865, 227, 495, 236, 911, 141, 942, 160, 769, 814, 770,
360, 576, 892, 530, 10, 544, 227, 376, 767, 488, 979, 838,
781, 324, 824, 185, 540, 854, 949, 288, 854, 487, 758, 937,
844, 199, 628, 649, 474, 943, 548, 640, 517, 801, 902, 169,
764, 549, 947, 876, 599, 734, 569, 94, 623, 439, 11, 228,
753, 103, 436, 143, 723, 378, 726, 193, 915, 794, 132, 769,
243, 174, 705, 953, 880, 475, 12, 618, 920, 484, 875, 506,
261, 367, 592, 591, 270, 774, 842, 263, 246, 692, 750, 346,
783, 43, 280, 530, 32, 694, 175, 784, 169, 921, 509, 88,
62, 177, 230, 530, 228, 146, 459, 506, 307, 405, 276, 786,
698, 697, 3, 687, 585, 633, 185, 738, 629, 50, 953, 312,
348, 274, 583, 707, 297, 108, 602, 852, 943, 724, 391, 871,
767, 846, 752, 885, 584, 433, 397, 762, 261, 837, 868, 90,
881, 922, 211, 433, 584, 318, 731, 804, 566, 291, 609, 591,
323, 205, 858, 740, 268, 137, 548, 737, 796, 493, 690, 827,
50, 761, 392, 239, 96, 476, 526, 190, 539, 860, 875, 71,
204, 159, 973, 592, 666, 939, 906, 4, 977, 309, 789, 715,
637, 817, 491, 260, 608, 295, 919, 71, 581, 174, 888, 291,
586, 53, 125, 317, 232, 72, 80, 191, 640, 684, 503, 446,
475, 540, 689, 901, 353, 427, 274, 463, 74, 875, 42, 875,
719, 518, 236, 482, 599, 242, 768, 755, 370, 940, 116, 666,
70, 660, 329, 219, 317, 896, 927, 618, 803, 398, 947, 132,
730, 234, 604, 165, 897, 3, 258, 982, 586, 665, 957, 775,
18, 730, 676, 785, 841, 395, 709, 586, 337, 120, 283, 569,
372, 237, 997, 513, 668, 905, 557, 904, 306, 321, 807, 374,
318, 640, 184, 277, 562, 491, 195, 965, 487, 738, 133, 948,
726, 710, 377, 73, 729, 285, 554, 327, 348, 315, 996, 578,
1000, 432, 514, 69, 729, 701, 756, 87, 532, 45, 595, 261,
529, 782, 600, 88, 775, 683, 217, 300, 722, 138, 871, 453,
832, 245, 374, 3, 678, 246, 961, 755, 721, 191, 956, 656,
1, 138, 116, 437, 773, 947, 369, 4, 277, 445, 954, 926,
861, 246, 299, 457, 566, 291, 720, 715, 932, 798, 210, 807,
128, 961, 318, 139, 337, 802, 600, 72, 449, 957, 1, 345,
100, 615, 757, 970, 136, 95, 775, 251, 139, 640, 277, 609,
31, 170, 451, 838, 830, 542, 372, 752, 482, 958, 660, 380,
584, 531, 849, 622, 804, 100, 884, 758, 26, 737, 818, 339,
76, 169, 768, 495, 733, 966, 874, 89, 157, 306, 181, 415,
219, 443, 564, 275, 12, 611, 651, 505, 455, 961, 591, 149,
597, 580, 767, 99, 462, 52, 358, 496, 421, 50, 858, 632,
449, 335, 610, 241, 478, 605, 899, 449, 49, 347, 126, 932,
310, 464, 447, 933, 637, 758, 45, 110, 934, 866, 166, 33,
880, 956, 457, 30, 967, 592, 301, 157, 534, 414, 854, 107,
650, 444, 673, 24, 177, 361, 39, 561, 412, 901, 242, 284,
884, 796, 815, 264, 689, 363, 154, 849, 77, 992, 907, 625,
650, 147, 39, 308, 914, 524, 332, 549, 443, 219, 618, 498,
970, 833, 359, 728, 898, 851, 835, 830, 218, 938, 355, 238,
185, 242, 785, 716 } ;
    int i ;
    bt = NULL ;
    printf ( "Binary tree sort.\n" ) ;
    printf ( "\nArray:\n" ) ;
    //for ( i = 0 ; i <= 999 ; i++ )
    //    printf ( "%d\t", arr[i] ) ;
    for ( i = 0 ; i <= 999 ; i++ )
        insert ( &bt, arr[i] ) ;
    printf ( "\nIn-order traversal of binary tree:\n" ) ;
    inorder ( bt ) ;
}
void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;
        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}
void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        //printf ( "%d\t", sr -> data ) ;
        inorder ( sr -> rightchild ) ;
    }
}
