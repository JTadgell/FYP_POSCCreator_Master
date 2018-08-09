#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_ChannelAFirCoefficients

/* Number of FIR filter taps are: 85 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0xADu, 0x00u, 0x00u, 0x00u, /* Tap(0), 2.06232070922852E-05 */

 0x95u, 0x00u, 0x00u, 0x00u, /* Tap(1), 1.77621841430664E-05 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(2), 0 */

 0xE7u, 0xFEu, 0xFFu, 0x00u, /* Tap(3), -3.34978103637695E-05 */

 0xD2u, 0xFDu, 0xFFu, 0x00u, /* Tap(4), -6.65187835693359E-05 */

 0xDFu, 0xFDu, 0xFFu, 0x00u, /* Tap(5), -6.49690628051758E-05 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(6), 0 */

 0xD6u, 0x03u, 0x00u, 0x00u, /* Tap(7), 0.000117063522338867 */

 0x17u, 0x07u, 0x00u, 0x00u, /* Tap(8), 0.000216364860534668 */

 0x72u, 0x06u, 0x00u, 0x00u, /* Tap(9), 0.000196695327758789 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(10), 0 */

 0xC3u, 0xF5u, 0xFFu, 0x00u, /* Tap(11), -0.000312447547912598 */

 0x0Du, 0xEEu, 0xFFu, 0x00u, /* Tap(12), -0.00054776668548584 */

 0x6Cu, 0xF0u, 0xFFu, 0x00u, /* Tap(13), -0.000475406646728516 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(14), 0 */

 0xE6u, 0x16u, 0x00u, 0x00u, /* Tap(15), 0.00069880485534668 */

 0xD3u, 0x26u, 0x00u, 0x00u, /* Tap(16), 0.00118482112884521 */

 0xB5u, 0x20u, 0x00u, 0x00u, /* Tap(17), 0.000998139381408691 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(18), 0 */

 0x60u, 0xD2u, 0xFFu, 0x00u, /* Tap(19), -0.00139236450195313 */

 0x60u, 0xB4u, 0xFFu, 0x00u, /* Tap(20), -0.00230789184570313 */

 0x9Au, 0xC1u, 0xFFu, 0x00u, /* Tap(21), -0.00190424919128418 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(22), 0 */

 0xFDu, 0x53u, 0x00u, 0x00u, /* Tap(23), 0.00256311893463135 */

 0x21u, 0x89u, 0x00u, 0x00u, /* Tap(24), 0.00418484210968018 */

 0xA9u, 0x6Fu, 0x00u, 0x00u, /* Tap(25), 0.00340759754180908 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(26), 0 */

 0xC4u, 0x6Cu, 0xFFu, 0x00u, /* Tap(27), -0.00449323654174805 */

 0x43u, 0x11u, 0xFFu, 0x00u, /* Tap(28), -0.0072857141494751 */

 0x74u, 0x3Eu, 0xFFu, 0x00u, /* Tap(29), -0.00590658187866211 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(30), 0 */

 0x67u, 0xFFu, 0x00u, 0x00u, /* Tap(31), 0.00779426097869873 */

 0xC4u, 0xA0u, 0x01u, 0x00u, /* Tap(32), 0.012718677520752 */

 0xD8u, 0x55u, 0x01u, 0x00u, /* Tap(33), 0.010432243347168 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(34), 0 */

 0xABu, 0x27u, 0xFEu, 0x00u, /* Tap(35), -0.0144144296646118 */

 0xB0u, 0xDDu, 0xFCu, 0x00u, /* Tap(36), -0.0244846343994141 */

 0x4Du, 0x46u, 0xFDu, 0x00u, /* Tap(37), -0.0212920904159546 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(38), 0 */

 0xF3u, 0xB4u, 0x04u, 0x00u, /* Tap(39), 0.0367721319198608 */

 0x96u, 0x18u, 0x0Au, 0x00u, /* Tap(40), 0.0788753032684326 */

 0x89u, 0x5Fu, 0x0Eu, 0x00u, /* Tap(41), 0.112290501594543 */

 0xFFu, 0xFFu, 0x0Fu, 0x00u, /* Tap(42), 0.12499988079071 */

 0x89u, 0x5Fu, 0x0Eu, 0x00u, /* Tap(43), 0.112290501594543 */

 0x96u, 0x18u, 0x0Au, 0x00u, /* Tap(44), 0.0788753032684326 */

 0xF3u, 0xB4u, 0x04u, 0x00u, /* Tap(45), 0.0367721319198608 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(46), 0 */

 0x4Du, 0x46u, 0xFDu, 0x00u, /* Tap(47), -0.0212920904159546 */

 0xB0u, 0xDDu, 0xFCu, 0x00u, /* Tap(48), -0.0244846343994141 */

 0xABu, 0x27u, 0xFEu, 0x00u, /* Tap(49), -0.0144144296646118 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(50), 0 */

 0xD8u, 0x55u, 0x01u, 0x00u, /* Tap(51), 0.010432243347168 */

 0xC4u, 0xA0u, 0x01u, 0x00u, /* Tap(52), 0.012718677520752 */

 0x67u, 0xFFu, 0x00u, 0x00u, /* Tap(53), 0.00779426097869873 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(54), 0 */

 0x74u, 0x3Eu, 0xFFu, 0x00u, /* Tap(55), -0.00590658187866211 */

 0x43u, 0x11u, 0xFFu, 0x00u, /* Tap(56), -0.0072857141494751 */

 0xC4u, 0x6Cu, 0xFFu, 0x00u, /* Tap(57), -0.00449323654174805 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(58), 0 */

 0xA9u, 0x6Fu, 0x00u, 0x00u, /* Tap(59), 0.00340759754180908 */

 0x21u, 0x89u, 0x00u, 0x00u, /* Tap(60), 0.00418484210968018 */

 0xFDu, 0x53u, 0x00u, 0x00u, /* Tap(61), 0.00256311893463135 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(62), 0 */

 0x9Au, 0xC1u, 0xFFu, 0x00u, /* Tap(63), -0.00190424919128418 */

 0x60u, 0xB4u, 0xFFu, 0x00u, /* Tap(64), -0.00230789184570313 */

 0x60u, 0xD2u, 0xFFu, 0x00u, /* Tap(65), -0.00139236450195313 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(66), 0 */

 0xB5u, 0x20u, 0x00u, 0x00u, /* Tap(67), 0.000998139381408691 */

 0xD3u, 0x26u, 0x00u, 0x00u, /* Tap(68), 0.00118482112884521 */

 0xE6u, 0x16u, 0x00u, 0x00u, /* Tap(69), 0.00069880485534668 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(70), 0 */

 0x6Cu, 0xF0u, 0xFFu, 0x00u, /* Tap(71), -0.000475406646728516 */

 0x0Du, 0xEEu, 0xFFu, 0x00u, /* Tap(72), -0.00054776668548584 */

 0xC3u, 0xF5u, 0xFFu, 0x00u, /* Tap(73), -0.000312447547912598 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(74), 0 */

 0x72u, 0x06u, 0x00u, 0x00u, /* Tap(75), 0.000196695327758789 */

 0x17u, 0x07u, 0x00u, 0x00u, /* Tap(76), 0.000216364860534668 */

 0xD6u, 0x03u, 0x00u, 0x00u, /* Tap(77), 0.000117063522338867 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(78), 0 */

 0xDFu, 0xFDu, 0xFFu, 0x00u, /* Tap(79), -6.49690628051758E-05 */

 0xD2u, 0xFDu, 0xFFu, 0x00u, /* Tap(80), -6.65187835693359E-05 */

 0xE7u, 0xFEu, 0xFFu, 0x00u, /* Tap(81), -3.34978103637695E-05 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(82), 0 */

 0x95u, 0x00u, 0x00u, 0x00u, /* Tap(83), 1.77621841430664E-05 */

 0xADu, 0x00u, 0x00u, 0x00u, /* Tap(84), 2.06232070922852E-05 */
};

