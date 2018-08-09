#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_1_ChannelAFirCoefficients

/* Number of FIR filter taps are: 16 */

const uint8 CYCODE Filter_1_ChannelAFirCoefficients[Filter_1_FIR_A_SIZE] = 
{
 0xCCu, 0x76u, 0x00u, 0x00u, /* Tap(0), 0.00362539291381836 */

 0xFCu, 0xF4u, 0x00u, 0x00u, /* Tap(1), 0.0074763298034668 */

 0xDCu, 0xF1u, 0x01u, 0x00u, /* Tap(2), 0.0151934623718262 */

 0x11u, 0x5Fu, 0x03u, 0x00u, /* Tap(3), 0.0263386964797974 */

 0x63u, 0x0Du, 0x05u, 0x00u, /* Tap(4), 0.0394710302352905 */

 0xDDu, 0xB5u, 0x06u, 0x00u, /* Tap(5), 0.0524250268936157 */

 0x15u, 0x0Au, 0x08u, 0x00u, /* Tap(6), 0.0628076791763306 */

 0x50u, 0xC7u, 0x08u, 0x00u, /* Tap(7), 0.0685825347900391 */

 0x50u, 0xC7u, 0x08u, 0x00u, /* Tap(8), 0.0685825347900391 */

 0x15u, 0x0Au, 0x08u, 0x00u, /* Tap(9), 0.0628076791763306 */

 0xDDu, 0xB5u, 0x06u, 0x00u, /* Tap(10), 0.0524250268936157 */

 0x63u, 0x0Du, 0x05u, 0x00u, /* Tap(11), 0.0394710302352905 */

 0x11u, 0x5Fu, 0x03u, 0x00u, /* Tap(12), 0.0263386964797974 */

 0xDCu, 0xF1u, 0x01u, 0x00u, /* Tap(13), 0.0151934623718262 */

 0xFCu, 0xF4u, 0x00u, 0x00u, /* Tap(14), 0.0074763298034668 */

 0xCCu, 0x76u, 0x00u, 0x00u, /* Tap(15), 0.00362539291381836 */
};

