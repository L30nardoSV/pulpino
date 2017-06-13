/////////////////////////////////////////////////////////
// includes
/////////////////////////////////////////////////////////
#include "mlDist.h"
#include "bar.h"
#include "utils.h"
#include "bench.h"
#include "math_fns.h"

/////////////////////////////////////////////////////////
// shared globals
/////////////////////////////////////////////////////////

  //__attribute__ ((section(".heapsram"))) 
  __attribute__ ((section(".heapsram"))) static const float fv0[1200] = { 94.430336F, 47.4179039F, 7.76787376F,
    33.8475647F, 62.7342224F, 96.6340714F, 67.2861328F, 30.3696175F, 40.0897102F,
    36.9409943F, 61.7380714F, 94.3065491F, 60.2187042F, 31.6917515F, 87.2750778F,
    67.8570557F, 96.8142624F, 33.1510391F, 79.384819F, 79.3637466F, 73.8073F,
    49.3659248F, 51.2116318F, 22.8868904F, 73.4920578F, 70.57267F, 61.3598938F,
    47.5032883F, 39.4533577F, 16.7725391F, 92.0682602F, 56.3749809F, 53.6219788F,
    87.8346558F, 64.3056335F, 98.8335266F, 45.0544052F, 71.21521F, 34.3078537F,
    45.6649704F, 15.447957F, 12.6158552F, 53.5045F, 8.50775242F, 22.7475643F,
    94.7409821F, 27.765625F, 1.21100283F, 28.4930553F, 17.9885864F, 31.6876888F,
    79.9492111F, 17.1151657F, 41.5483055F, 5.88832426F, 17.6349125F, 88.6347961F,
    99.3754349F, 5.79202127F, 93.1865768F, 88.642334F, 66.4412689F, 92.8839493F,
    86.1743622F, 79.1097107F, 37.7364197F, 28.1150913F, 15.1504507F, 67.9015F,
    0.611498535F, 15.5168171F, 82.2401428F, 79.9063797F, 26.2475224F,
    71.3286133F, 94.2452164F, 85.6527786F, 87.5999222F, 31.6278381F, 83.9840469F,
    88.1552429F, 67.4112396F, 5.51392508F, 46.1094933F, 89.7445145F, 7.55144882F,
    50.1146889F, 13.3778486F, 44.0954399F, 35.2483521F, 48.0098305F, 78.7969666F,
    54.7011719F, 1.73639143F, 65.7079315F, 2.16680384F, 57.4255562F, 63.5888214F,
    39.7641029F, 32.9030571F, 44.7273674F, 73.2210922F, 67.8491058F, 38.4403076F,
    72.9405136F, 15.9668093F, 32.7937927F, 44.1155624F, 34.0686531F, 20.554285F,
    96.7678909F, 47.6767807F, 91.796F, 45.7314339F, 85.977005F, 4.41060686F,
    45.2022247F, 8.77247906F, 74.2673569F, 69.2598419F, 79.0766373F, 40.3062668F,
    18.7851028F, 48.9161072F, 16.1607742F, 38.6534042F, 52.6797142F, 49.1730766F,
    65.5829315F, 49.288063F, 30.2422447F, 53.7539368F, 8.99815083F, 38.4485F,
    34.5472107F, 79.7556763F, 61.8758545F, 71.9244308F, 74.5107117F, 37.8824844F,
    20.2933331F, 75.3143463F, 8.7605629F, 25.388052F, 98.5032425F, 74.4373932F,
    13.4119081F, 2.8650713F, 23.3404217F, 16.629776F, 41.1787529F, 21.5845F,
    47.9614639F, 88.0978622F, 66.5839081F, 41.7210884F, 99.5320511F, 14.0860119F,
    47.0190468F, 18.2860298F, 81.7617569F, 28.4473801F, 55.1602859F, 33.5959854F,
    87.5474243F, 18.4027805F, 8.13550758F, 43.6528702F, 64.075F, 32.2589722F,
    27.5168056F, 52.9606895F, 49.1097946F, 56.9240379F, 89.1528549F, 91.2416077F,
    85.0616837F, 67.9677124F, 10.7255468F, 49.1982918F, 1.50411403F, 33.0193863F,
    27.5969963F, 98.275856F, 97.2017288F, 84.448349F, 42.3999634F, 81.4770508F,
    73.5826569F, 99.4807129F, 76.1098557F, 49.2323303F, 67.8372269F, 28.6377144F,
    79.4873657F, 21.8128548F, 27.3373833F, 4.12752485F, 82.2447891F, 44.0753517F,
    30.2114391F, 29.3620682F, 12.7264557F, 27.2670612F, 15.1572704F, 4.88982677F,
    70.5793F, 33.9313393F, 32.2524414F, 1.65609217F, 61.7301559F, 80.8164749F,
    2.4385891F, 19.6386833F, 38.8934898F, 57.6585503F, 89.8173F, 84.3647079F,
    14.7902403F, 13.6163015F, 45.9718933F, 20.8782F, 44.384552F, 31.3938351F,
    44.9556694F, 21.3781128F, 94.1435394F, 17.4706306F, 20.7451439F, 47.6716728F,
    63.5000763F, 45.7219963F, 90.6468506F, 84.6516495F, 7.30462265F, 81.1550674F,
    57.7790184F, 87.5317383F, 99.6625519F, 84.291069F, 17.0920696F, 52.0977173F,
    92.004715F, 75.3398361F, 26.7365818F, 72.1569901F, 23.055027F, 48.7369232F,
    45.6153259F, 82.1549606F, 17.6589012F, 69.729393F, 89.1545868F, 64.8133087F,
    69.8256F, 43.6392136F, 12.8848257F, 96.8449249F, 87.6663666F, 17.9756565F,
    41.6926155F, 59.0745621F, 53.1233177F, 47.2604942F, 84.1191254F, 95.8737183F,
    76.693924F, 7.14148378F, 99.1439F, 13.1499052F, 12.3385611F, 95.6126099F,
    36.0470924F, 34.9038162F, 27.4111614F, 63.1281815F, 0.31436193F, 3.52427626F,
    37.6916618F, 18.5384789F, 29.2835407F, 89.3293686F, 65.2714539F, 28.8020649F,
    45.2587395F, 46.0150299F, 34.5801582F, 81.022377F, 16.2657394F, 55.6987953F,
    80.5864182F, 73.291275F, 12.3399267F, 84.466507F, 22.1684F, 98.6068802F,
    43.9013138F, 23.1593571F, 90.2931595F, 50.8665161F, 16.8257561F, 61.6989784F,
    69.7547302F, 11.0053358F, 20.6595135F, 39.466259F, 17.7978306F, 70.6787415F,
    48.4643135F, 86.8653F, 69.0900803F, 67.5142822F, 44.9369736F, 9.9773531F,
    43.1477F, 35.4691849F, 89.2260132F, 10.288414F, 49.2025909F, 57.5719872F,
    0.0810912475F, 98.7358475F, 68.2675171F, 65.6726074F, 36.9497528F,
    7.58769083F, 19.005579F, 97.7056046F, 61.3398552F, 33.9073029F, 50.2729378F,
    74.9547577F, 86.9469452F, 31.9083595F, 98.1731262F, 73.9221725F, 29.9327583F,
    89.985939F, 70.6178665F, 12.9447813F, 11.8285742F, 38.3131523F, 54.9121323F,
    73.7438126F, 72.4329529F, 31.3519154F, 58.737236F, 34.154068F, 72.6357F,
    53.7691536F, 73.7061615F, 95.9609451F, 88.9780121F, 56.6368599F, 42.5067787F,
    59.4390717F, 68.0684128F, 77.9376755F, 59.5441475F, 28.1441822F, 94.0471878F,
    90.636322F, 8.11064911F, 36.4494438F, 90.7319717F, 29.7440414F, 21.7101021F,
    67.269928F, 11.1491423F, 88.081459F, 48.9587975F, 51.4892883F, 25.9252987F,
    2.13883758F, 99.9913254F, 54.4388275F, 98.9162674F, 71.6829758F, 68.5948639F,
    5.52080965F, 20.1708336F, 26.171524F, 93.8304596F, 52.5039635F, 74.4967651F,
    78.0107422F, 72.2595367F, 68.1370316F, 91.4301376F, 75.6912842F, 6.75604725F,
    42.9194183F, 71.9754181F, 18.5555935F, 80.7411728F, 72.1318207F, 49.3205185F,
    0.912341714F, 75.4530411F, 84.7620773F, 74.6583633F, 77.8907242F,
    54.9923668F, 93.2772827F, 10.3365097F, 97.9058685F, 71.5369F, 56.5521088F,
    39.8662682F, 8.54824734F, 82.9211807F, 19.4122276F, 96.1026917F, 45.6374F,
    42.7316284F, 40.3551559F, 35.8907776F, 52.7054176F, 96.5906601F, 1.50384355F,
    6.89324713F, 69.5521317F, 78.4716415F, 2.21189737F, 92.614357F, 32.2382317F,
    50.8310318F, 20.5477505F, 88.2857513F, 31.374218F, 63.7664566F, 57.333252F,
    25.771059F, 67.9705F, 41.0536652F, 84.5802078F, 47.0564F, 0.532254457F,
    85.1203461F, 44.9190483F, 89.7416229F, 32.579483F, 6.15535069F, 42.2187042F,
    43.8148918F, 6.34453964F, 51.0642891F, 99.6728058F, 14.1096878F, 59.8811722F,
    38.5318375F, 98.7878F, 83.9975F, 52.6814384F, 87.7405396F, 49.1243172F,
    44.4828796F, 42.9849892F, 72.284F, 41.2035065F, 77.0257721F, 94.5589F,
    3.80709052F, 65.2975311F, 25.8143864F, 29.5414124F, 67.3642426F, 65.9015961F,
    42.492527F, 36.8079758F, 27.3647804F, 26.2111874F, 81.918869F, 42.0464516F,
    18.9166985F, 18.96595F, 92.6532593F, 18.3447247F, 76.2970428F, 97.7155075F,
    65.1299133F, 91.9093628F, 16.8507195F, 3.39685559F, 40.090004F, 63.344574F,
    74.4995651F, 20.4414082F, 59.3770828F, 87.5821F, 59.9150658F, 93.5467911F,
    19.819273F, 1.30890906F, 3.40179634F, 21.7779274F, 46.4823F, 1.30970514F,
    35.2361641F, 47.2941551F, 86.6378479F, 79.5380859F, 23.9444141F, 33.4860344F,
    87.4832611F, 78.1144333F, 89.4814F, 57.7524109F, 76.7201F, 45.4051552F,
    39.1535416F, 84.8572845F, 4.06499577F, 33.1250877F, 13.6851702F, 47.0847969F,
    37.3140144F, 58.6966896F, 55.492939F, 68.4181747F, 39.0545959F, 30.0604706F,
    57.134716F, 71.0572739F, 98.2177429F, 46.31073F, 5.20857859F, 95.1139221F,
    9.54238415F, 64.3608932F, 22.4742584F, 49.2176247F, 60.8218117F, 3.11405849F,
    55.3831787F, 90.2377F, 39.4915848F, 36.3612099F, 84.1731949F, 55.5510712F,
    1.35872555F, 45.9961166F, 85.4621506F, 63.4872932F, 59.9658508F, 64.7795105F,
    66.9101486F, 94.6500778F, 41.0606918F, 33.4381638F, 55.5352364F, 81.4863434F,
    44.2317162F, 9.34812546F, 70.660881F, 0.834877849F, 70.8212204F, 4.25625229F,
    53.2990227F, 45.2753334F, 75.6519852F, 61.9009438F, 35.2882843F, 95.7151184F,
    66.2685852F, 38.8456306F, 17.5449543F, 93.0645828F, 36.9984474F, 48.504528F,
    64.0952911F, 0.132604048F, 96.5324936F, 98.9877777F, 18.9683475F, 43.671524F,
    60.0685158F, 70.1917114F, 50.5382118F, 53.1188965F, 12.4668684F, 6.59052086F,
    69.7486954F, 85.693573F, 10.1803713F, 33.6561508F, 69.3088074F, 96.4588776F,
    8.99280643F, 73.5597382F, 94.3906F, 74.1850204F, 31.5619049F, 77.3945618F,
    40.4735947F, 98.2444229F, 72.3831406F, 75.4945145F, 55.3584518F, 15.3177214F,
    88.7028198F, 86.1450806F, 63.859684F, 15.0414305F, 94.6254272F, 38.2558212F,
    89.4970856F, 76.7678375F, 11.9725018F, 54.2302F, 7.7609849F, 1.55294383F,
    44.3726578F, 13.7032766F, 94.434967F, 50.1465912F, 75.1102753F, 36.22089F,
    58.8738174F, 84.2012405F, 20.0653954F, 90.1402893F, 97.8246918F, 6.83675337F,
    50.1085548F, 29.8152332F, 20.7066021F, 21.0095062F, 50.8170052F, 83.266716F,
    73.2638931F, 76.7869F, 1.97916603F, 71.2024841F, 22.8178158F, 34.8490181F,
    57.0372086F, 22.8853722F, 14.2269306F, 99.2764664F, 89.8917694F, 54.5048294F,
    86.1277313F, 83.2673187F, 19.2336292F, 10.9795923F, 99.0164642F, 92.5953217F,
    3.18639612F, 96.4634933F, 17.2446346F, 66.8650589F, 72.8168945F, 38.6030235F,
    17.0552883F, 93.6378632F, 38.7370872F, 13.1931324F, 56.872364F, 73.7656708F,
    3.24925923F, 90.4838F, 41.683815F, 47.0354F, 87.5989075F, 28.615387F,
    30.619194F, 55.1639481F, 69.2653F, 53.5667534F, 36.7669F, 71.8443909F,
    4.43013906F, 37.6257744F, 38.3286247F, 42.81007F, 42.0235748F, 88.5448303F,
    53.2514076F, 73.5564575F, 80.0741348F, 78.1872F, 38.5764885F, 53.3410492F,
    66.300087F, 23.4839134F, 5.16811037F, 90.9000473F, 12.7598829F, 84.1019363F,
    76.3103714F, 74.9984283F, 29.9482841F, 57.5531464F, 83.7145F, 72.817627F,
    91.1097946F, 12.3739376F, 41.3931923F, 51.6556625F, 83.959137F, 90.0435486F,
    49.0969086F, 88.7149734F, 87.1593094F, 85.8463058F, 56.2531624F, 97.0626144F,
    66.9533768F, 12.9831142F, 26.1210194F, 92.4324722F, 34.9937706F, 7.02029419F,
    37.9675F, 11.4366388F, 80.6863861F, 19.986845F, 10.8241491F, 69.2382736F,
    79.7630615F, 81.0069504F, 14.3123026F, 67.517807F, 47.3446274F, 12.3180027F,
    3.1077435F, 1.08530116F, 36.6358414F, 32.4682198F, 6.78788519F, 87.6493073F,
    36.8513565F, 18.2530022F, 0.114416391F, 86.4887238F, 57.6408272F,
    92.0508118F, 64.5644836F, 6.25037432F, 37.2402763F, 58.5383415F, 7.20053625F,
    5.77297401F, 17.9825039F, 79.4218F, 90.3048325F, 61.1174202F, 46.9780655F,
    61.7932892F, 59.1774559F, 94.203804F, 13.9021864F, 75.4591293F, 90.1704407F,
    94.4119568F, 7.06872368F, 96.8653564F, 41.8436241F, 14.8955832F, 16.9860897F,
    27.3495865F, 81.3355331F, 25.0601597F, 2.78988457F, 4.55073643F, 50.5435677F,
    26.4318485F, 57.7613449F, 46.638382F, 81.5603714F, 19.454607F, 99.5395355F,
    32.4324303F, 50.0859642F, 59.3891029F, 30.3054142F, 2.16402769F, 92.0862427F,
    44.9873581F, 26.2191086F, 78.4821625F, 54.40242F, 84.9528503F, 49.1786842F,
    46.2465019F, 55.3955879F, 39.8902F, 4.34878302F, 88.4510803F, 17.9755878F,
    43.5793343F, 56.3235512F, 95.6312485F, 98.7080383F, 84.2587433F, 8.78077698F,
    94.4086533F, 93.9645F, 40.4162712F, 36.7112F, 18.5021839F, 71.3528061F,
    61.7216873F, 46.4647255F, 80.4945F, 22.2094746F, 22.5025482F, 95.6929779F,
    36.4398155F, 95.1059F, 35.6317368F, 9.47733879F, 39.2671127F, 95.0168304F,
    94.9978867F, 20.3647289F, 19.2975693F, 30.738512F, 88.4799423F, 13.4997711F,
    85.4244385F, 20.3816795F, 18.4801292F, 14.1605911F, 52.0839233F, 67.1975784F,
    91.5997925F, 40.3215F, 99.9441452F, 92.3605804F, 20.586689F, 90.9651718F,
    1.11422539F, 66.255806F, 31.0712681F, 88.9443893F, 73.4777298F, 89.4879074F,
    21.8348713F, 60.9489326F, 69.0231476F, 78.9165268F, 36.2888069F, 29.8528557F,
    54.919651F, 66.9681549F, 77.4073257F, 72.6623688F, 12.7589016F, 54.4927216F,
    54.9049911F, 48.8292084F, 46.2860641F, 14.5814724F, 22.212F, 45.2649536F,
    74.9117355F, 9.32176F, 92.1091843F, 5.51775503F, 82.3451462F, 57.1383705F,
    68.2746582F, 61.4538307F, 86.0865784F, 92.8339767F, 78.6830063F, 35.2840805F,
    24.036087F, 45.7853737F, 98.5149612F, 61.1621F, 67.1082687F, 24.0212231F,
    84.8478165F, 45.186573F, 63.4959068F, 67.3789825F, 9.66015244F, 96.5840912F,
    86.8437347F, 88.0315933F, 82.3706055F, 28.3010025F, 49.7598152F, 11.1027594F,
    80.1598358F, 37.024292F, 97.299F, 23.5398884F, 40.1181831F, 11.8976727F,
    68.9779587F, 81.4355164F, 13.9150791F, 3.19405913F, 33.36F, 91.0164337F,
    64.021904F, 38.8164864F, 66.7404861F, 80.8687515F, 63.9869156F, 60.0747681F,
    61.7764F, 38.2132263F, 39.2504883F, 68.9580612F, 76.1451797F, 95.7426453F,
    59.7764282F, 44.5064659F, 68.3416061F, 10.6510124F, 44.6454277F, 89.7054749F,
    46.0689468F, 91.5641251F, 26.817173F, 74.1632614F, 73.4874725F, 38.5231628F,
    5.09103966F, 38.4234352F, 78.9285F, 50.3284721F, 52.8182602F, 98.9885F,
    73.7331314F, 20.529705F, 29.1300259F, 26.8410473F, 29.6003075F, 69.8008041F,
    77.6026611F, 1.00273955F, 11.5057402F, 37.0336952F, 44.2303696F, 81.3824F,
    48.1749878F, 86.144249F, 12.3642578F, 40.2793465F, 37.7876816F, 68.1605377F,
    53.7972031F, 41.7026024F, 28.1310253F, 35.2693367F, 10.8823843F, 40.8835564F,
    58.2770042F, 13.94732F, 98.3106766F, 78.8737183F, 7.60182619F, 14.2536783F,
    63.0987816F, 15.7254581F, 76.0098F, 28.2066F, 36.7671776F, 60.1833611F,
    84.2376F, 95.8899384F, 34.9760551F, 5.48662F, 81.5159378F, 73.3940353F,
    55.0225563F, 33.5008659F, 69.6185F, 78.0202408F, 27.8346367F, 25.7965603F,
    37.755825F, 67.5217209F, 9.04718781F, 77.5614929F, 13.6116219F, 67.7740784F,
    77.0249F, 46.0155678F, 96.2494125F, 99.3507233F, 73.7491F, 65.1407394F,
    31.3591156F, 21.6083F, 54.7183F, 46.6831551F, 0.228054449F, 72.7918167F,
    54.1170883F, 4.71590614F, 75.4218597F, 53.6929817F, 76.6458282F, 79.5548172F,
    3.79283428F, 22.089941F, 27.7213192F, 72.8480759F, 36.7422485F, 20.5124F,
    23.1440468F, 17.5036678F, 80.6418152F, 8.10521126F, 59.54813F, 36.1146088F,
    85.0466766F, 71.1966248F, 79.2409668F, 40.6422272F, 45.3117561F, 76.5080948F,
    55.0160446F, 25.1440506F, 17.6675224F, 9.8733387F, 64.2649765F, 2.31556892F,
    66.4886322F, 54.6731606F, 68.3963165F, 32.5950127F, 90.2326126F, 70.8311081F,
    97.9439316F, 72.7872086F, 21.6413898F, 13.9940653F, 87.5532532F, 40.0024452F,
    68.9043655F, 55.8595924F, 4.51252127F, 90.5401535F, 91.2506866F, 85.4617081F,
    40.1573257F, 4.34704924F, 99.840065F, 24.3944588F, 44.6221962F, 61.7746696F,
    79.8169174F, 86.9480286F, 56.8753052F, 12.0172205F, 37.3978653F, 42.5049858F,
    30.0354023F, 88.914772F, 88.7659073F, 85.3027344F, 55.5683441F, 33.8372536F,
    23.7771111F, 36.6086F, 59.899147F, 94.7423248F, 22.8566761F, 6.83359718F,
    22.1666889F, 40.918F, 18.4236355F, 24.0102539F, 4.34259605F, 43.802166F,
    49.8254509F, 28.8703613F, 23.8775082F, 8.01151371F, 8.17033482F, 58.6503296F,
    54.5285263F, 57.2804489F, 20.5759F, 1.35320139F, 33.0115814F, 87.859169F,
    23.2083416F, 64.1195374F, 94.1250534F, 9.5509634F, 10.411005F, 50.7060814F,
    33.1386185F, 74.2279F, 70.4457626F, 50.3746223F, 58.6143188F, 18.6861839F,
    85.5405273F, 81.1578903F, 0.0283103064F, 90.2383347F, 1.680902F, 30.6218643F,
    25.3370056F, 29.548233F, 92.3464355F, 69.1116333F, 32.850853F, 36.2320518F,
    30.7404976F, 55.61063F, 49.6472397F, 44.6857452F, 86.9329F, 75.3336716F,
    64.9520721F, 43.0104485F, 49.5262451F, 56.9876251F, 20.7018185F, 90.6420822F,
    74.0799332F, 31.8359432F, 70.8291245F, 16.9808731F, 37.3523598F, 69.4036789F,
    6.38809443F, 42.9453506F, 40.7518616F, 37.3915825F, 1.88747621F, 28.3989792F,
    51.2789116F, 82.8404388F, 98.6580353F, 49.9402809F, 32.5793228F, 80.5619888F,
    15.1978951F, 44.972187F, 55.9722137F, 98.0065384F, 60.8509903F, 68.3461761F,
    82.5485306F, 7.17078066F, 87.6415939F, 2.40694952F, 3.63633013F, 97.3949356F,
    26.5588551F, 87.2024078F, 13.5334072F, 48.8235817F, 7.75637436F, 82.9893112F,
    69.9272842F, 14.9824276F, 79.2324066F, 83.9722366F, 2.34207129F, 50.0062828F,
    73.2609F, 4.31510639F, 58.9791031F, 62.2416458F, 47.5627899F, 77.147171F,
    82.2459793F, 24.949194F, 50.316925F, 37.026371F, 58.9948578F, 46.9624901F,
    46.6435204F, 11.0961723F, 9.34033489F, 73.7763824F, 75.5978317F, 95.9926529F,
    93.1373138F, 54.3308792F, 12.5923805F, 82.2045746F, 63.8542252F, 86.6807404F,
    78.8059387F, 45.7108955F, 40.0221F, 19.1326866F, 92.9010086F, 52.912632F,
    67.6135712F, 44.6582909F, 83.8390045F, 87.9641876F, 91.78862F, 61.5817909F,
    35.2929153F };

  __attribute__ ((section(".heapsram"))) static const float fv1[16] = { 9608.58398F, 9608.39258F, 858.173218F, 858.156F,
    10032.5742F, 10032.373F, 662.106323F, 662.09314F, 10100.6611F, 10100.46F,
    712.823242F, 712.80896F, 9564.94F, 9564.74902F, 784.073853F, 784.058228F };

/////////////////////////////////////////////////////////
// subfunctions
/////////////////////////////////////////////////////////

/*
 * Arguments    : const float x[100]
 * Return Type  : float
 */
float sum(const float x[100])
{
  float y;
  int k;
  y = x[0];
  for (k = 0; k < 99; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const float x[100]
 * Return Type  : float
 */
float var(const float x[100])
{
  float y;
  int ix;
  float xbar;
  int k;
  float r;
  ix = 0;
  xbar = x[0];
  for (k = 0; k < 99; k++) {
    ix++;
    xbar += x[ix];
  }

  xbar *= 1.0F/100.0F;
  ix = 0;
  r = x[0] - xbar;
  y = r * r;
  for (k = 0; k < 99; k++) {
    ix++;
    r = x[ix] - xbar;
    y += r * r;
  }

  y *= 1.0F/99.0F;
  return y;
}

/*
 * Arguments    : const float check[2]
 *                const float golden[4]
 * Return Type  : boolean_T
 */
boolean_T checkRes(const float check[2], const float golden[4])
{
  int k;
  boolean_T y, flag;
  y = true;
  for (k = 0; k < 2; k++) {
    flag = true;
    flag = flag && (check[k] <= golden[k << 1]);
    flag = flag && (check[k] >= golden[1 + (k << 1)]);
    printErrors(!flag, k, check[k] ,golden[k<<1] ,golden[1+(k<<1)]);
    y = y && flag;
  }

  return y;
}


/////////////////////////////////////////////////////////
// main testing function 
/////////////////////////////////////////////////////////
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  int coreid;
  int it;

  float tmp[2];
  boolean_T pass;
  float d[100];
  int k,j;
  float * x;

  /////////////////////////////////////////////////////////
  // main test loop 
  // each core loops over a kernel instance
  /////////////////////////////////////////////////////////
  
  coreid = get_core_id();

  printf("starting %d kernel iterations... (coreid = %d)\n",KERNEL_ITS,coreid);

  if (coreid>3)
    coreid=coreid-4;

  synch_barrier();
  
  perf_begin();
  
  x = (float*)&fv0[300 * coreid];

  for(it = 0; it < getKernelIts(); it++)
  {

    /*  mlDist vector 2-norm */
    j = 0;
    for (k = 0; k < 300; k+=3) {
      d[j] = fSqrt( x[k]   * x[k]   + 
		    x[k+1] * x[k+1] + 
		    x[k+2] * x[k+2] );
      j++;
    }

  }

  synch_barrier();

  perf_end();


  /////////////////////////////////////////////////////////
  // check results
  /////////////////////////////////////////////////////////
  tmp[0] = sum(d);
  tmp[1] = var(d);
  pass = checkRes(tmp, *(float (*)[4])&fv1[coreid << 2]);

  flagPassFail(pass, get_core_id());
  
/////////////////////////////////////////////////////////
// synchronize and exit
/////////////////////////////////////////////////////////

  return !pass;
}

