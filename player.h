
class Player
{
public:
    
    // Variables
    
    // Mesh variables
//    float vertices[1584];
//    float normals[1584];
//    int indices[2048];
    
    float vertices[1584] = {0.540000, 3.840000, 0.000000, 0.498895, 3.840000, -0.206649, 0.381838, 3.840000, -0.381838, 0.206649, 3.840000, -0.498895, 0.000000, 3.840000, -0.540000, -0.206649, 3.840000, -0.498895, -0.381838, 3.840000, -0.381838, -0.498895, 3.840000, -0.206649, -0.540000, 3.840000, -0.000000, -0.498895, 3.840000, 0.206649, -0.381838, 3.840000, 0.381838, -0.206649, 3.840000, 0.498895, -0.000000, 3.840000, 0.540000, 0.206649, 3.840000, 0.498895, 0.381838, 3.840000, 0.381838, 0.498895, 3.840000, 0.206649, 0.552480, 3.534609, 0.000000, 0.510425, 3.534609, -0.211425, 0.390663, 3.534609, -0.390663, 0.211425, 3.534609, -0.510425, 0.000000, 3.534609, -0.552480, -0.211425, 3.534609, -0.510425, -0.390663, 3.534609, -0.390663, -0.510425, 3.534609, -0.211425, -0.552480, 3.534609, -0.000000, -0.510425, 3.534609, 0.211425, -0.390663, 3.534609, 0.390663, -0.211425, 3.534609, 0.510425, -0.000000, 3.534609, 0.552480, 0.211425, 3.534609, 0.510425, 0.390663, 3.534609, 0.390663, 0.510425, 3.534609, 0.211425, 0.564844, 3.226875, 0.000000, 0.521848, 3.226875, -0.216156, 0.399405, 3.226875, -0.399405, 0.216156, 3.226875, -0.521848, 0.000000, 3.226875, -0.564844, -0.216156, 3.226875, -0.521848, -0.399405, 3.226875, -0.399405, -0.521848, 3.226875, -0.216156, -0.564844, 3.226875, -0.000000, -0.521848, 3.226875, 0.216156, -0.399405, 3.226875, 0.399405, -0.216156, 3.226875, 0.521848, -0.000000, 3.226875, 0.564844, 0.216156, 3.226875, 0.521848, 0.399405, 3.226875, 0.399405, 0.521848, 3.226875, 0.216156, 0.576951, 2.913501, 0.000000, 0.533033, 2.913501, -0.220789, 0.407966, 2.913501, -0.407966, 0.220789, 2.913501, -0.533033, -0.000000, 2.913501, -0.576951, -0.220789, 2.913501, -0.533033, -0.407966, 2.913501, -0.407966, -0.533033, 2.913501, -0.220789, -0.576951, 2.913501, -0.000000, -0.533033, 2.913501, 0.220789, -0.407966, 2.913501, 0.407966, -0.220789, 2.913501, 0.533033, -0.000000, 2.913501, 0.576951, 0.220789, 2.913501, 0.533033, 0.407966, 2.913501, 0.407966, 0.533033, 2.913501, 0.220789, 0.588750, 2.595000, 0.000000, 0.543934, 2.595000, -0.225305, 0.416309, 2.595000, -0.416309, 0.225305, 2.595000, -0.543934, -0.000000, 2.595000, -0.588750, -0.225305, 2.595000, -0.543934, -0.416309, 2.595000, -0.416309, -0.543934, 2.595000, -0.225305, -0.588750, 2.595000, -0.000000, -0.543934, 2.595000, 0.225305, -0.416309, 2.595000, 0.416309, -0.225305, 2.595000, 0.543934, -0.000000, 2.595000, 0.588750, 0.225305, 2.595000, 0.543934, 0.416309, 2.595000, 0.416309, 0.543934, 2.595000, 0.225305, 0.600256, 2.274741, 0.000000, 0.554565, 2.274741, -0.229708, 0.424445, 2.274741, -0.424445, 0.229708, 2.274741, -0.554565, -0.000000, 2.274741, -0.600256, -0.229708, 2.274741, -0.554565, -0.424445, 2.274741, -0.424445, -0.554565, 2.274741, -0.229708, -0.600256, 2.274741, -0.000000, -0.554565, 2.274741, 0.229708, -0.424445, 2.274741, 0.424445, -0.229708, 2.274741, 0.554565, -0.000000, 2.274741, 0.600256, 0.229708, 2.274741, 0.554565, 0.424445, 2.274741, 0.424445, 0.554565, 2.274741, 0.229708, 0.611133, 1.940859, 0.000000, 0.564613, 1.940859, -0.233870, 0.432136, 1.940859, -0.432136, 0.233870, 1.940859, -0.564613, -0.000000, 1.940859, -0.611133, -0.233870, 1.940859, -0.564613, -0.432136, 1.940859, -0.432136, -0.564613, 1.940859, -0.233870, -0.611133, 1.940859, 0.000000, -0.564613, 1.940859, 0.233870, -0.432136, 1.940859, 0.432136, -0.233870, 1.940859, 0.564613, -0.000000, 1.940859, 0.611133, 0.233870, 1.940859, 0.564613, 0.432136, 1.940859, 0.432136, 0.564613, 1.940859, 0.233870, 0.621196, 1.588154, 0.000000, 0.573911, 1.588154, -0.237722, 0.439252, 1.588154, -0.439252, 0.237722, 1.588154, -0.573911, -0.000000, 1.588154, -0.621196, -0.237722, 1.588154, -0.573911, -0.439252, 1.588154, -0.439252, -0.573911, 1.588154, -0.237722, -0.621196, 1.588154, -0.000000, -0.573911, 1.588154, 0.237722, -0.439252, 1.588154, 0.439252, -0.237722, 1.588154, 0.573911, -0.000000, 1.588154, 0.621196, 0.237722, 1.588154, 0.573911, 0.439252, 1.588154, 0.439252, 0.573911, 1.588154, 0.237722, 0.630000, 1.200000, 0.000000, 0.582044, 1.200000, -0.241091, 0.445477, 1.200000, -0.445477, 0.241091, 1.200000, -0.582044, 0.000000, 1.200000, -0.630000, -0.241091, 1.200000, -0.582044, -0.445477, 1.200000, -0.445477, -0.582044, 1.200000, -0.241091, -0.630000, 1.200000, 0.000000, -0.582044, 1.200000, 0.241091, -0.445477, 1.200000, 0.445477, -0.241091, 1.200000, 0.582044, -0.000000, 1.200000, 0.630000, 0.241091, 1.200000, 0.582044, 0.445477, 1.200000, 0.445477, 0.582044, 1.200000, 0.241091, 0.636811, 0.747393, 0.000000, 0.588337, 0.747393, -0.243697, 0.450294, 0.747393, -0.450294, 0.243697, 0.747393, -0.588337, 0.000000, 0.747393, -0.636811, -0.243697, 0.747393, -0.588337, -0.450294, 0.747393, -0.450294, -0.588337, 0.747393, -0.243697, -0.636811, 0.747393, -0.000000, -0.588337, 0.747393, 0.243697, -0.450294, 0.747393, 0.450294, -0.243697, 0.747393, 0.588337, -0.000000, 0.747393, 0.636811, 0.243697, 0.747393, 0.588337, 0.450294, 0.747393, 0.450294, 0.588337, 0.747393, 0.243697, 0.642305, 0.262266, 0.000000, 0.593412, 0.262266, -0.245799, 0.454178, 0.262266, -0.454178, 0.245799, 0.262266, -0.593412, 0.000000, 0.262266, -0.642305, -0.245799, 0.262266, -0.593412, -0.454178, 0.262266, -0.454178, -0.593412, 0.262266, -0.245799, -0.642305, 0.262266, 0.000000, -0.593412, 0.262266, 0.245799, -0.454178, 0.262266, 0.454178, -0.245799, 0.262266, 0.593412, -0.000000, 0.262266, 0.642305, 0.245799, 0.262266, 0.593412, 0.454178, 0.262266, 0.454178, 0.593412, 0.262266, 0.245799, 0.647036, -0.235320, 0.000000, 0.597783, -0.235320, -0.247610, 0.457524, -0.235320, -0.457524, 0.247610, -0.235320, -0.597783, 0.000000, -0.235320, -0.647036, -0.247610, -0.235320, -0.597783, -0.457524, -0.235320, -0.457524, -0.597783, -0.235320, -0.247610, -0.647036, -0.235320, -0.000000, -0.597783, -0.235320, 0.247610, -0.457524, -0.235320, 0.457524, -0.247610, -0.235320, 0.597783, 0.000000, -0.235320, 0.647036, 0.247610, -0.235320, 0.597783, 0.457524, -0.235320, 0.457524, 0.597783, -0.235320, 0.247610, 0.650625, -0.738750, 0.000000, 0.601099, -0.738750, -0.248983, 0.460061, -0.738750, -0.460061, 0.248983, -0.738750, -0.601099, 0.000000, -0.738750, -0.650625, -0.248983, -0.738750, -0.601099, -0.460061, -0.738750, -0.460061, -0.601099, -0.738750, -0.248983, -0.650625, -0.738750, 0.000000, -0.601099, -0.738750, 0.248983, -0.460061, -0.738750, 0.460061, -0.248983, -0.738750, 0.601099, -0.000000, -0.738750, 0.650625, 0.248983, -0.738750, 0.601099, 0.460061, -0.738750, 0.460061, 0.601099, -0.738750, 0.248983, 0.652339, -1.236262, -0.000000, 0.602683, -1.236262, -0.249639, 0.461273, -1.236262, -0.461273, 0.249639, -1.236262, -0.602683, 0.000000, -1.236262, -0.652339, -0.249639, -1.236262, -0.602683, -0.461273, -1.236262, -0.461273, -0.602683, -1.236262, -0.249639, -0.652339, -1.236262, -0.000000, -0.602683, -1.236262, 0.249639, -0.461273, -1.236262, 0.461273, -0.249639, -1.236262, 0.602683, 0.000000, -1.236262, 0.652339, 0.249639, -1.236262, 0.602683, 0.461273, -1.236262, 0.461273, 0.602683, -1.236262, 0.249639, 0.653789, -1.723242, 0.000000, 0.604022, -1.723242, -0.250194, 0.462299, -1.723242, -0.462299, 0.250194, -1.723242, -0.604022, 0.000000, -1.723242, -0.653789, -0.250194, -1.723242, -0.604022, -0.462299, -1.723242, -0.462299, -0.604022, -1.723242, -0.250194, -0.653789, -1.723242, 0.000000, -0.604022, -1.723242, 0.250194, -0.462299, -1.723242, 0.462299, -0.250194, -1.723242, 0.604022, -0.000000, -1.723242, 0.653789, 0.250194, -1.723242, 0.604022, 0.462299, -1.723242, 0.462299, 0.604022, -1.723242, 0.250194, 0.655474, -2.195757, 0.000000, 0.605579, -2.195757, -0.250839, 0.463490, -2.195757, -0.463490, 0.250839, -2.195757, -0.605579, 0.000000, -2.195757, -0.655474, -0.250839, -2.195757, -0.605579, -0.463490, -2.195757, -0.463490, -0.605579, -2.195757, -0.250839, -0.655474, -2.195757, -0.000000, -0.605579, -2.195757, 0.250839, -0.463490, -2.195757, 0.463490, -0.250839, -2.195757, 0.605579, 0.000000, -2.195757, 0.655474, 0.250839, -2.195757, 0.605579, 0.463490, -2.195757, 0.463490, 0.605579, -2.195757, 0.250839, 0.660000, -2.640000, 0.000000, 0.609760, -2.640000, -0.252571, 0.466690, -2.640000, -0.466690, 0.252571, -2.640000, -0.609760, 0.000000, -2.640000, -0.660000, -0.252571, -2.640000, -0.609760, -0.466690, -2.640000, -0.466690, -0.609760, -2.640000, -0.252571, -0.660000, -2.640000, -0.000000, -0.609760, -2.640000, 0.252571, -0.466690, -2.640000, 0.466690, -0.252571, -2.640000, 0.609760, -0.000000, -2.640000, 0.660000, 0.252571, -2.640000, 0.609760, 0.466690, -2.640000, 0.466690, 0.609760, -2.640000, 0.252571, 0.672144, -3.036548, -0.000000, 0.620980, -3.036548, -0.257218, 0.475277, -3.036548, -0.475277, 0.257218, -3.036548, -0.620980, 0.000000, -3.036548, -0.672144, -0.257218, -3.036548, -0.620980, -0.475277, -3.036548, -0.475277, -0.620980, -3.036548, -0.257218, -0.672144, -3.036548, -0.000000, -0.620980, -3.036548, 0.257218, -0.475277, -3.036548, 0.475277, -0.257218, -3.036548, 0.620980, 0.000000, -3.036548, 0.672144, 0.257218, -3.036548, 0.620980, 0.475277, -3.036548, 0.475277, 0.620980, -3.036548, 0.257218, 0.685898, -3.398320, 0.000000, 0.633688, -3.398320, -0.262482, 0.485003, -3.398320, -0.485003, 0.262482, -3.398320, -0.633688, 0.000000, -3.398320, -0.685898, -0.262482, -3.398320, -0.633688, -0.485003, -3.398320, -0.485003, -0.633688, -3.398320, -0.262482, -0.685898, -3.398320, -0.000000, -0.633688, -3.398320, 0.262482, -0.485003, -3.398320, 0.485003, -0.262482, -3.398320, 0.633688, -0.000000, -3.398320, 0.685898, 0.262482, -3.398320, 0.633688, 0.485003, -3.398320, 0.485003, 0.633688, -3.398320, 0.262482, 0.697119, -3.730994, 0.000000, 0.644054, -3.730994, -0.266776, 0.492938, -3.730994, -0.492938, 0.266776, -3.730994, -0.644054, 0.000000, -3.730994, -0.697119, -0.266776, -3.730994, -0.644054, -0.492938, -3.730994, -0.492938, -0.644054, -3.730994, -0.266776, -0.697119, -3.730994, -0.000000, -0.644054, -3.730994, 0.266776, -0.492938, -3.730994, 0.492938, -0.266776, -3.730994, 0.644054, 0.000000, -3.730994, 0.697119, 0.266776, -3.730994, 0.644054, 0.492938, -3.730994, 0.492938, 0.644054, -3.730994, 0.266776, 0.705000, -4.036875, 0.000000, 0.651335, -4.036875, -0.269792, 0.498510, -4.036875, -0.498510, 0.269792, -4.036875, -0.651335, 0.000000, -4.036875, -0.705000, -0.269792, -4.036875, -0.651335, -0.498510, -4.036875, -0.498510, -0.651335, -4.036875, -0.269792, -0.705000, -4.036875, -0.000000, -0.651335, -4.036875, 0.269792, -0.498510, -4.036875, 0.498510, -0.269792, -4.036875, 0.651335, 0.000000, -4.036875, 0.705000, 0.269792, -4.036875, 0.651335, 0.498510, -4.036875, 0.498510, 0.651335, -4.036875, 0.269792, 0.708545, -4.323831, -0.000000, 0.654610, -4.323831, -0.271148, 0.501017, -4.323831, -0.501017, 0.271148, -4.323831, -0.654610, 0.000000, -4.323831, -0.708545, -0.271148, -4.323831, -0.654610, -0.501017, -4.323831, -0.501017, -0.654610, -4.323831, -0.271148, -0.708545, -4.323831, -0.000000, -0.654610, -4.323831, 0.271148, -0.501017, -4.323831, 0.501017, -0.271148, -4.323831, 0.654610, -0.000000, -4.323831, 0.708545, 0.271148, -4.323831, 0.654610, 0.501017, -4.323831, 0.501017, 0.654610, -4.323831, 0.271148, 0.704180, -4.580859, 0.000000, 0.650577, -4.580859, -0.269478, 0.497930, -4.580859, -0.497930, 0.269478, -4.580859, -0.650577, -0.000000, -4.580859, -0.704180, -0.269478, -4.580859, -0.650577, -0.497930, -4.580859, -0.497930, -0.650577, -4.580859, -0.269478, -0.704180, -4.580859, -0.000000, -0.650577, -4.580859, 0.269478, -0.497930, -4.580859, 0.497930, -0.269478, -4.580859, 0.650577, -0.000000, -4.580859, 0.704180, 0.269478, -4.580859, 0.650577, 0.497930, -4.580859, 0.497930, 0.650577, -4.580859, 0.269478, 0.690132, -4.803194, 0.000000, 0.637599, -4.803194, -0.264102, 0.487997, -4.803194, -0.487997, 0.264102, -4.803194, -0.637599, 0.000000, -4.803194, -0.690132, -0.264102, -4.803194, -0.637599, -0.487997, -4.803194, -0.487997, -0.637599, -4.803194, -0.264102, -0.690132, -4.803194, 0.000000, -0.637599, -4.803194, 0.264102, -0.487997, -4.803194, 0.487997, -0.264102, -4.803194, 0.637599, -0.000000, -4.803194, 0.690132, 0.264102, -4.803194, 0.637599, 0.487997, -4.803194, 0.487997, 0.637599, -4.803194, 0.264102, 0.660000, -4.980000, 0.000000, 0.609760, -4.980000, -0.252571, 0.466690, -4.980000, -0.466690, 0.252571, -4.980000, -0.609760, 0.000000, -4.980000, -0.660000, -0.252571, -4.980000, -0.609760, -0.466690, -4.980000, -0.466690, -0.609760, -4.980000, -0.252571, -0.660000, -4.980000, -0.000000, -0.609760, -4.980000, 0.252571, -0.466690, -4.980000, 0.466690, -0.252571, -4.980000, 0.609760, 0.000000, -4.980000, 0.660000, 0.252571, -4.980000, 0.609760, 0.466690, -4.980000, 0.466690, 0.609760, -4.980000, 0.252571, 0.603267, -5.091182, -0.000000, 0.557346, -5.091182, -0.230860, 0.426574, -5.091182, -0.426574, 0.230860, -5.091182, -0.557346, 0.000000, -5.091182, -0.603267, -0.230860, -5.091182, -0.557346, -0.426574, -5.091182, -0.426574, -0.557346, -5.091182, -0.230860, -0.603267, -5.091182, -0.000000, -0.557346, -5.091182, 0.230860, -0.426574, -5.091182, 0.426574, -0.230860, -5.091182, 0.557346, -0.000000, -5.091182, 0.603267, 0.230860, -5.091182, 0.557346, 0.426574, -5.091182, 0.426574, 0.557346, -5.091182, 0.230860, 0.530508, -5.159766, -0.000000, 0.490125, -5.159766, -0.203017, 0.375126, -5.159766, -0.375126, 0.203017, -5.159766, -0.490125, -0.000000, -5.159766, -0.530508, -0.203017, -5.159766, -0.490125, -0.375126, -5.159766, -0.375126, -0.490125, -5.159766, -0.203017, -0.530508, -5.159766, -0.000000, -0.490125, -5.159766, 0.203017, -0.375126, -5.159766, 0.375126, -0.203017, -5.159766, 0.490125, -0.000000, -5.159766, 0.530508, 0.203017, -5.159766, 0.490125, 0.375126, -5.159766, 0.375126, 0.490125, -5.159766, 0.203017, 0.448015, -5.200019, 0.000000, 0.413912, -5.200019, -0.171448, 0.316795, -5.200019, -0.316795, 0.171448, -5.200019, -0.413912, 0.000000, -5.200019, -0.448015, -0.171448, -5.200019, -0.413912, -0.316795, -5.200019, -0.316795, -0.413912, -5.200019, -0.171448, -0.448015, -5.200019, 0.000000, -0.413912, -5.200019, 0.171448, -0.316795, -5.200019, 0.316795, -0.171448, -5.200019, 0.413912, -0.000000, -5.200019, 0.448015, 0.171448, -5.200019, 0.413912, 0.316795, -5.200019, 0.316795, 0.413912, -5.200019, 0.171448, 0.358125, -5.218125, 0.000000, 0.330864, -5.218125, -0.137048, 0.253233, -5.218125, -0.253233, 0.137048, -5.218125, -0.330864, 0.000000, -5.218125, -0.358125, -0.137048, -5.218125, -0.330864, -0.253233, -5.218125, -0.253233, -0.330864, -5.218125, -0.137048, -0.358125, -5.218125, -0.000000, -0.330864, -5.218125, 0.137048, -0.253233, -5.218125, 0.253233, -0.137048, -5.218125, 0.330864, 0.000000, -5.218125, 0.358125, 0.137048, -5.218125, 0.330864, 0.253233, -5.218125, 0.253233, 0.330864, -5.218125, 0.137048, 0.265481, -5.224980, -0.000000, 0.245272, -5.224980, -0.101595, 0.187723, -5.224980, -0.187723, 0.101595, -5.224980, -0.245272, 0.000000, -5.224980, -0.265481, -0.101595, -5.224980, -0.245272, -0.187723, -5.224980, -0.187723, -0.245272, -5.224980, -0.101595, -0.265481, -5.224980, -0.000000, -0.245272, -5.224980, 0.101595, -0.187723, -5.224980, 0.187723, -0.101595, -5.224980, 0.245272, -0.000000, -5.224980, 0.265481, 0.101595, -5.224980, 0.245272, 0.187723, -5.224980, 0.187723, 0.245272, -5.224980, 0.101595, 0.169453, -5.220703, 0.000000, 0.156554, -5.220703, -0.064847, 0.119821, -5.220703, -0.119821, 0.064847, -5.220703, -0.156554, -0.000000, -5.220703, -0.169453, -0.064847, -5.220703, -0.156554, -0.119821, -5.220703, -0.119821, -0.156554, -5.220703, -0.064847, -0.169453, -5.220703, -0.000000, -0.156554, -5.220703, 0.064847, -0.119821, -5.220703, 0.119821, -0.064847, -5.220703, 0.156554, -0.000000, -5.220703, 0.169453, 0.064847, -5.220703, 0.156554, 0.119821, -5.220703, 0.119821, 0.156554, -5.220703, 0.064847, 0.070400, -5.207432, 0.000000, 0.065041, -5.207432, -0.026941, 0.049781, -5.207432, -0.049781, 0.026941, -5.207432, -0.065041, 0.000000, -5.207432, -0.070400, -0.026941, -5.207432, -0.065041, -0.049781, -5.207432, -0.049781, -0.065041, -5.207432, -0.026941, -0.070400, -5.207432, 0.000000, -0.065041, -5.207432, 0.026941, -0.049781, -5.207432, 0.049781, -0.026941, -5.207432, 0.065041, -0.000000, -5.207432, 0.070400, 0.026941, -5.207432, 0.065041, 0.049781, -5.207432, 0.049781, 0.065041, -5.207432, 0.026941, -0.030000, -5.190000, -0.000000, -0.027716, -5.190000, 0.011481, -0.021213, -5.190000, 0.021213, -0.011481, -5.190000, 0.027716, -0.000000, -5.190000, 0.030000, 0.011481, -5.190000, 0.027716, 0.021213, -5.190000, 0.021213, 0.027716, -5.190000, 0.011481, 0.030000, -5.190000, 0.000000, 0.027716, -5.190000, -0.011481, 0.021213, -5.190000, -0.021213, 0.011481, -5.190000, -0.027716, -0.000000, -5.190000, -0.030000, -0.011481, -5.190000, -0.027716, -0.021213, -5.190000, -0.021213, -0.027716, -5.190000, -0.011481};

    float normals[1584] = {0.999166, 0.040833, 0.040833, 0.923109, 0.040833, 0.040833, 0.706517, 0.040833, 0.040833, 0.382364, 0.040833, 0.040833, 0.000000, 0.040833, 0.040833, -0.382364, 0.040833, 0.040833, -0.706517, 0.040833, 0.040833, -0.923109, 0.040833, 0.040833, -0.999166, 0.040833, 0.040833, -0.923109, 0.040833, 0.040833, -0.706517, 0.040833, 0.040833, -0.382364, 0.040833, 0.040833, -0.000000, 0.040833, 0.040833, 0.382364, 0.040833, 0.040833, 0.706517, 0.040833, 0.040833, 0.923109, 0.040833, 0.040833, 0.999180, 0.040488, 0.040488, 0.923122, 0.040488, 0.040488, 0.706527, 0.040488, 0.040488, 0.382370, 0.040488, 0.040488, 0.000000, 0.040488, 0.040488, -0.382370, 0.040488, 0.040488, -0.706527, 0.040488, 0.040488, -0.923122, 0.040488, 0.040488, -0.999180, 0.040488, 0.040488, -0.923122, 0.040488, 0.040488, -0.706527, 0.040488, 0.040488, -0.382370, 0.040488, 0.040488, -0.000000, 0.040488, 0.040488, 0.382370, 0.040488, 0.040488, 0.706527, 0.040488, 0.040488, 0.923122, 0.040488, 0.040488, 0.999225, 0.039374, 0.039374, 0.923163, 0.039374, 0.039374, 0.706558, 0.039374, 0.039374, 0.382387, 0.039374, 0.039374, 0.000000, 0.039374, 0.039374, -0.382387, 0.039374, 0.039374, -0.706558, 0.039374, 0.039374, -0.923163, 0.039374, 0.039374, -0.999225, 0.039374, 0.039374, -0.923163, 0.039374, 0.039374, -0.706558, 0.039374, 0.039374, -0.382387, 0.039374, 0.039374, -0.000000, 0.039374, 0.039374, 0.382387, 0.039374, 0.039374, 0.706558, 0.039374, 0.039374, 0.923163, 0.039374, 0.039374, 0.999285, 0.037813, 0.037813, 0.923219, 0.037813, 0.037813, 0.706601, 0.037813, 0.037813, 0.382410, 0.037813, 0.037813, 0.000000, 0.037813, 0.037813, -0.382410, 0.037813, 0.037813, -0.706601, 0.037813, 0.037813, -0.923219, 0.037813, 0.037813, -0.999285, 0.037813, 0.037813, -0.923219, 0.037813, 0.037813, -0.706601, 0.037813, 0.037813, -0.382410, 0.037813, 0.037813, -0.000000, 0.037813, 0.037813, 0.382410, 0.037813, 0.037813, 0.706601, 0.037813, 0.037813, 0.923219, 0.037813, 0.037813, 0.999335, 0.036463, 0.036463, 0.923265, 0.036463, 0.036463, 0.706637, 0.036463, 0.036463, 0.382429, 0.036463, 0.036463, 0.000000, 0.036463, 0.036463, -0.382429, 0.036463, 0.036463, -0.706637, 0.036463, 0.036463, -0.923265, 0.036463, 0.036463, -0.999335, 0.036463, 0.036463, -0.923265, 0.036463, 0.036463, -0.706637, 0.036463, 0.036463, -0.382429, 0.036463, 0.036463, -0.000000, 0.036463, 0.036463, 0.382429, 0.036463, 0.036463, 0.706637, 0.036463, 0.036463, 0.923265, 0.036463, 0.036463, 0.999414, 0.034232, 0.034232, 0.923338, 0.034232, 0.034232, 0.706692, 0.034232, 0.034232, 0.382459, 0.034232, 0.034232, -0.000000, 0.034232, 0.034232, -0.382459, 0.034232, 0.034232, -0.706692, 0.034232, 0.034232, -0.923338, 0.034232, 0.034232, -0.999414, 0.034232, 0.034232, -0.923338, 0.034232, 0.034232, -0.706692, 0.034232, 0.034232, -0.382459, 0.034232, 0.034232, -0.000000, 0.034232, 0.034232, 0.382459, 0.034232, 0.034232, 0.706692, 0.034232, 0.034232, 0.923338, 0.034232, 0.034232, 0.999534, 0.030540, 0.030540, 0.923449, 0.030540, 0.030540, 0.706777, 0.030540, 0.030540, 0.382505, 0.030540, 0.030540, -0.000000, 0.030540, 0.030540, -0.382505, 0.030540, 0.030540, -0.706777, 0.030540, 0.030540, -0.923449, 0.030540, 0.030540, -0.999534, 0.030540, 0.030540, -0.923449, 0.030540, 0.030540, -0.706777, 0.030540, 0.030540, -0.382505, 0.030540, 0.030540, -0.000000, 0.030540, 0.030540, 0.382505, 0.030540, 0.030540, 0.706777, 0.030540, 0.030540, 0.923449, 0.030540, 0.030540, 0.999672, 0.025598, 0.025598, 0.923577, 0.025598, 0.025598, 0.706875, 0.025598, 0.025598, 0.382558, 0.025598, 0.025598, -0.000000, 0.025598, 0.025598, -0.382558, 0.025598, 0.025598, -0.706875, 0.025598, 0.025598, -0.923577, 0.025598, 0.025598, -0.999672, 0.025598, 0.025598, -0.923577, 0.025598, 0.025598, -0.706875, 0.025598, 0.025598, -0.382558, 0.025598, 0.025598, -0.000000, 0.025598, 0.025598, 0.382558, 0.025598, 0.025598, 0.706875, 0.025598, 0.025598, 0.923577, 0.025598, 0.025598, 0.999822, 0.018862, 0.018862, 0.923715, 0.018862, 0.018862, 0.706981, 0.018862, 0.018862, 0.382615, 0.018862, 0.018862, 0.000000, 0.018862, 0.018862, -0.382615, 0.018862, 0.018862, -0.706981, 0.018862, 0.018862, -0.923715, 0.018862, 0.018862, -0.999822, 0.018862, 0.018862, -0.923715, 0.018862, 0.018862, -0.706981, 0.018862, 0.018862, -0.382615, 0.018862, 0.018862, -0.000000, 0.018862, 0.018862, 0.382615, 0.018862, 0.018862, 0.706981, 0.018862, 0.018862, 0.923715, 0.018862, 0.018862, 0.999913, 0.013185, 0.013185, 0.923799, 0.013185, 0.013185, 0.707045, 0.013185, 0.013185, 0.382650, 0.013185, 0.013185, 0.000000, 0.013185, 0.013185, -0.382650, 0.013185, 0.013185, -0.707045, 0.013185, 0.013185, -0.923799, 0.013185, 0.013185, -0.999913, 0.013185, 0.013185, -0.923799, 0.013185, 0.013185, -0.707045, 0.013185, 0.013185, -0.382650, 0.013185, 0.013185, -0.000000, 0.013185, 0.013185, 0.382650, 0.013185, 0.013185, 0.707045, 0.013185, 0.013185, 0.923799, 0.013185, 0.013185, 0.999946, 0.010415, 0.010415, 0.923829, 0.010415, 0.010415, 0.707068, 0.010415, 0.010415, 0.382663, 0.010415, 0.010415, 0.000000, 0.010415, 0.010415, -0.382663, 0.010415, 0.010415, -0.707068, 0.010415, 0.010415, -0.923829, 0.010415, 0.010415, -0.999946, 0.010415, 0.010415, -0.923829, 0.010415, 0.010415, -0.707068, 0.010415, 0.010415, -0.382663, 0.010415, 0.010415, -0.000000, 0.010415, 0.010415, 0.382663, 0.010415, 0.010415, 0.707068, 0.010415, 0.010415, 0.923829, 0.010415, 0.010415, 0.999965, 0.008319, 0.008319, 0.923848, 0.008319, 0.008319, 0.707082, 0.008319, 0.008319, 0.382670, 0.008319, 0.008319, 0.000000, 0.008319, 0.008319, -0.382670, 0.008319, 0.008319, -0.707082, 0.008319, 0.008319, -0.923848, 0.008319, 0.008319, -0.999965, 0.008319, 0.008319, -0.923848, 0.008319, 0.008319, -0.707082, 0.008319, 0.008319, -0.382670, 0.008319, 0.008319, -0.000000, 0.008319, 0.008319, 0.382670, 0.008319, 0.008319, 0.707082, 0.008319, 0.008319, 0.923848, 0.008319, 0.008319, 0.999986, 0.005287, 0.005287, 0.923867, 0.005287, 0.005287, 0.707097, 0.005287, 0.005287, 0.382678, 0.005287, 0.005287, 0.000000, 0.005287, 0.005287, -0.382678, 0.005287, 0.005287, -0.707097, 0.005287, 0.005287, -0.923867, 0.005287, 0.005287, -0.999986, 0.005287, 0.005287, -0.923867, 0.005287, 0.005287, -0.707097, 0.005287, 0.005287, -0.382678, 0.005287, 0.005287, -0.000000, 0.005287, 0.005287, 0.382678, 0.005287, 0.005287, 0.707097, 0.005287, 0.005287, 0.923867, 0.005287, 0.005287, 0.999995, 0.003211, 0.003211, 0.923875, 0.003211, 0.003211, 0.707103, 0.003211, 0.003211, 0.382681, 0.003211, 0.003211, 0.000000, 0.003211, 0.003211, -0.382681, 0.003211, 0.003211, -0.707103, 0.003211, 0.003211, -0.923875, 0.003211, 0.003211, -0.999995, 0.003211, 0.003211, -0.923875, 0.003211, 0.003211, -0.707103, 0.003211, 0.003211, -0.382681, 0.003211, 0.003211, -0.000000, 0.003211, 0.003211, 0.382681, 0.003211, 0.003211, 0.707103, 0.003211, 0.003211, 0.923875, 0.003211, 0.003211, 0.999995, 0.003272, 0.003272, 0.923875, 0.003272, 0.003272, 0.707103, 0.003272, 0.003272, 0.382681, 0.003272, 0.003272, 0.000000, 0.003272, 0.003272, -0.382681, 0.003272, 0.003272, -0.707103, 0.003272, 0.003272, -0.923875, 0.003272, 0.003272, -0.999995, 0.003272, 0.003272, -0.923875, 0.003272, 0.003272, -0.707103, 0.003272, 0.003272, -0.382681, 0.003272, 0.003272, -0.000000, 0.003272, 0.003272, 0.382681, 0.003272, 0.003272, 0.707103, 0.003272, 0.003272, 0.923875, 0.003272, 0.003272, 0.999976, 0.006877, 0.006877, 0.923858, 0.006877, 0.006877, 0.707090, 0.006877, 0.006877, 0.382674, 0.006877, 0.006877, 0.000000, 0.006877, 0.006877, -0.382674, 0.006877, 0.006877, -0.707090, 0.006877, 0.006877, -0.923858, 0.006877, 0.006877, -0.999976, 0.006877, 0.006877, -0.923858, 0.006877, 0.006877, -0.707090, 0.006877, 0.006877, -0.382674, 0.006877, 0.006877, -0.000000, 0.006877, 0.006877, 0.382674, 0.006877, 0.006877, 0.707090, 0.006877, 0.006877, 0.923858, 0.006877, 0.006877, 0.999792, 0.020400, 0.020400, 0.923687, 0.020400, 0.020400, 0.706960, 0.020400, 0.020400, 0.382604, 0.020400, 0.020400, 0.000000, 0.020400, 0.020400, -0.382604, 0.020400, 0.020400, -0.706960, 0.020400, 0.020400, -0.923687, 0.020400, 0.020400, -0.999792, 0.020400, 0.020400, -0.923687, 0.020400, 0.020400, -0.706960, 0.020400, 0.020400, -0.382604, 0.020400, 0.020400, -0.000000, 0.020400, 0.020400, 0.382604, 0.020400, 0.020400, 0.706960, 0.020400, 0.020400, 0.923687, 0.020400, 0.020400, 0.999412, 0.034301, 0.034301, 0.923336, 0.034301, 0.034301, 0.706691, 0.034301, 0.034301, 0.382458, 0.034301, 0.034301, 0.000000, 0.034301, 0.034301, -0.382458, 0.034301, 0.034301, -0.706691, 0.034301, 0.034301, -0.923336, 0.034301, 0.034301, -0.999412, 0.034301, 0.034301, -0.923336, 0.034301, 0.034301, -0.706691, 0.034301, 0.034301, -0.382458, 0.034301, 0.034301, -0.000000, 0.034301, 0.034301, 0.382458, 0.034301, 0.034301, 0.706691, 0.034301, 0.034301, 0.923336, 0.034301, 0.034301, 0.999357, 0.035852, 0.035852, 0.923286, 0.035852, 0.035852, 0.706652, 0.035852, 0.035852, 0.382437, 0.035852, 0.035852, 0.000000, 0.035852, 0.035852, -0.382437, 0.035852, 0.035852, -0.706652, 0.035852, 0.035852, -0.923286, 0.035852, 0.035852, -0.999357, 0.035852, 0.035852, -0.923286, 0.035852, 0.035852, -0.706652, 0.035852, 0.035852, -0.382437, 0.035852, 0.035852, -0.000000, 0.035852, 0.035852, 0.382437, 0.035852, 0.035852, 0.706652, 0.035852, 0.035852, 0.923286, 0.035852, 0.035852, 0.999558, 0.029733, 0.029733, 0.923471, 0.029733, 0.029733, 0.706794, 0.029733, 0.029733, 0.382514, 0.029733, 0.029733, 0.000000, 0.029733, 0.029733, -0.382514, 0.029733, 0.029733, -0.706794, 0.029733, 0.029733, -0.923471, 0.029733, 0.029733, -0.999558, 0.029733, 0.029733, -0.923471, 0.029733, 0.029733, -0.706794, 0.029733, 0.029733, -0.382514, 0.029733, 0.029733, -0.000000, 0.029733, 0.029733, 0.382514, 0.029733, 0.029733, 0.706794, 0.029733, 0.029733, 0.923471, 0.029733, 0.029733, 0.999818, 0.019055, 0.019055, 0.923712, 0.019055, 0.019055, 0.706978, 0.019055, 0.019055, 0.382614, 0.019055, 0.019055, 0.000000, 0.019055, 0.019055, -0.382614, 0.019055, 0.019055, -0.706978, 0.019055, 0.019055, -0.923712, 0.019055, 0.019055, -0.999818, 0.019055, 0.019055, -0.923712, 0.019055, 0.019055, -0.706978, 0.019055, 0.019055, -0.382614, 0.019055, 0.019055, -0.000000, 0.019055, 0.019055, 0.382614, 0.019055, 0.019055, 0.706978, 0.019055, 0.019055, 0.923712, 0.019055, 0.019055, 0.999997, -0.002314, -0.002314, 0.923877, -0.002314, -0.002314, 0.707105, -0.002314, -0.002314, 0.382682, -0.002314, -0.002314, 0.000000, -0.002314, -0.002314, -0.382682, -0.002314, -0.002314, -0.707105, -0.002314, -0.002314, -0.923877, -0.002314, -0.002314, -0.999997, -0.002314, -0.002314, -0.923877, -0.002314, -0.002314, -0.707105, -0.002314, -0.002314, -0.382682, -0.002314, -0.002314, -0.000000, -0.002314, -0.002314, 0.382682, -0.002314, -0.002314, 0.707105, -0.002314, -0.002314, 0.923877, -0.002314, -0.002314, 0.999198, -0.040031, -0.040031, 0.923139, -0.040031, -0.040031, 0.706540, -0.040031, -0.040031, 0.382377, -0.040031, -0.040031, 0.000000, -0.040031, -0.040031, -0.382377, -0.040031, -0.040031, -0.706540, -0.040031, -0.040031, -0.923139, -0.040031, -0.040031, -0.999198, -0.040031, -0.040031, -0.923139, -0.040031, -0.040031, -0.706540, -0.040031, -0.040031, -0.382377, -0.040031, -0.040031, -0.000000, -0.040031, -0.040031, 0.382377, -0.040031, -0.040031, 0.706540, -0.040031, -0.040031, 0.923139, -0.040031, -0.040031, 0.993284, -0.115703, -0.115703, 0.917675, -0.115703, -0.115703, 0.702358, -0.115703, -0.115703, 0.380113, -0.115703, -0.115703, 0.000000, -0.115703, -0.115703, -0.380113, -0.115703, -0.115703, -0.702358, -0.115703, -0.115703, -0.917675, -0.115703, -0.115703, -0.993284, -0.115703, -0.115703, -0.917675, -0.115703, -0.115703, -0.702358, -0.115703, -0.115703, -0.380113, -0.115703, -0.115703, -0.000000, -0.115703, -0.115703, 0.380113, -0.115703, -0.115703, 0.702358, -0.115703, -0.115703, 0.917675, -0.115703, -0.115703, 0.949053, -0.315115, -0.315115, 0.876811, -0.315115, -0.315115, 0.671082, -0.315115, -0.315115, 0.363187, -0.315115, -0.315115, 0.000000, -0.315115, -0.315115, -0.363187, -0.315115, -0.315115, -0.671082, -0.315115, -0.315115, -0.876811, -0.315115, -0.315115, -0.949053, -0.315115, -0.315115, -0.876811, -0.315115, -0.315115, -0.671082, -0.315115, -0.315115, -0.363187, -0.315115, -0.315115, -0.000000, -0.315115, -0.315115, 0.363187, -0.315115, -0.315115, 0.671082, -0.315115, -0.315115, 0.876811, -0.315115, -0.315115, 0.799748, -0.600336, -0.600336, 0.738871, -0.600336, -0.600336, 0.565507, -0.600336, -0.600336, 0.306050, -0.600336, -0.600336, 0.000000, -0.600336, -0.600336, -0.306050, -0.600336, -0.600336, -0.565507, -0.600336, -0.600336, -0.738871, -0.600336, -0.600336, -0.799748, -0.600336, -0.600336, -0.738871, -0.600336, -0.600336, -0.565507, -0.600336, -0.600336, -0.306050, -0.600336, -0.600336, -0.000000, -0.600336, -0.600336, 0.306050, -0.600336, -0.600336, 0.565507, -0.600336, -0.600336, 0.738871, -0.600336, -0.600336, 0.568359, -0.822780, -0.822780, 0.525096, -0.822780, -0.822780, 0.401891, -0.822780, -0.822780, 0.217502, -0.822780, -0.822780, 0.000000, -0.822780, -0.822780, -0.217502, -0.822780, -0.822780, -0.401891, -0.822780, -0.822780, -0.525096, -0.822780, -0.822780, -0.568359, -0.822780, -0.822780, -0.525096, -0.822780, -0.822780, -0.401891, -0.822780, -0.822780, -0.217502, -0.822780, -0.822780, -0.000000, -0.822780, -0.822780, 0.217502, -0.822780, -0.822780, 0.401891, -0.822780, -0.822780, 0.525096, -0.822780, -0.822780, 0.320421, -0.947275, -0.947275, 0.296030, -0.947275, -0.947275, 0.226572, -0.947275, -0.947275, 0.122620, -0.947275, -0.947275, 0.000000, -0.947275, -0.947275, -0.122620, -0.947275, -0.947275, -0.226572, -0.947275, -0.947275, -0.296030, -0.947275, -0.947275, -0.320421, -0.947275, -0.947275, -0.296030, -0.947275, -0.947275, -0.226572, -0.947275, -0.947275, -0.122620, -0.947275, -0.947275, -0.000000, -0.947275, -0.947275, 0.122620, -0.947275, -0.947275, 0.226572, -0.947275, -0.947275, 0.296030, -0.947275, -0.947275, 0.135869, -0.990727, -0.990727, 0.125526, -0.990727, -0.990727, 0.096074, -0.990727, -0.990727, 0.051995, -0.990727, -0.990727, 0.000000, -0.990727, -0.990727, -0.051995, -0.990727, -0.990727, -0.096074, -0.990727, -0.990727, -0.125526, -0.990727, -0.990727, -0.135869, -0.990727, -0.990727, -0.125526, -0.990727, -0.990727, -0.096074, -0.990727, -0.990727, -0.051995, -0.990727, -0.990727, -0.000000, -0.990727, -0.990727, 0.051995, -0.990727, -0.990727, 0.096074, -0.990727, -0.990727, 0.125526, -0.990727, -0.990727, 0.014672, -0.999892, -0.999892, 0.013556, -0.999892, -0.999892, 0.010375, -0.999892, -0.999892, 0.005615, -0.999892, -0.999892, 0.000000, -0.999892, -0.999892, -0.005615, -0.999892, -0.999892, -0.010375, -0.999892, -0.999892, -0.013556, -0.999892, -0.999892, -0.014672, -0.999892, -0.999892, -0.013556, -0.999892, -0.999892, -0.010375, -0.999892, -0.999892, -0.005615, -0.999892, -0.999892, -0.000000, -0.999892, -0.999892, 0.005615, -0.999892, -0.999892, 0.010375, -0.999892, -0.999892, 0.013556, -0.999892, -0.999892, -0.088728, -0.996056, -0.996056, -0.081974, -0.996056, -0.996056, -0.062740, -0.996056, -0.996056, -0.033955, -0.996056, -0.996056, -0.000000, -0.996056, -0.996056, 0.033955, -0.996056, -0.996056, 0.062740, -0.996056, -0.996056, 0.081974, -0.996056, -0.996056, 0.088728, -0.996056, -0.996056, 0.081974, -0.996056, -0.996056, 0.062740, -0.996056, -0.996056, 0.033955, -0.996056, -0.996056, 0.000000, -0.996056, -0.996056, -0.033955, -0.996056, -0.996056, -0.062740, -0.996056, -0.996056, -0.081974, -0.996056, -0.996056, -0.151956, -0.988387, -0.988387, -0.140389, -0.988387, -0.988387, -0.107449, -0.988387, -0.988387, -0.058151, -0.988387, -0.988387, -0.000000, -0.988387, -0.988387, 0.058151, -0.988387, -0.988387, 0.107449, -0.988387, -0.988387, 0.140389, -0.988387, -0.988387, 0.151956, -0.988387, -0.988387, 0.140389, -0.988387, -0.988387, 0.107449, -0.988387, -0.988387, 0.058151, -0.988387, -0.988387, 0.000000, -0.988387, -0.988387, -0.058151, -0.988387, -0.988387, -0.107449, -0.988387, -0.988387, -0.140389, -0.988387, -0.988387, -0.171062, -0.985260, -0.985260, -0.158041, -0.985260, -0.985260, -0.120959, -0.985260, -0.985260, -0.065463, -0.985260, -0.985260, -0.000000, -0.985260, -0.985260, 0.065463, -0.985260, -0.985260, 0.120959, -0.985260, -0.985260, 0.158041, -0.985260, -0.985260, 0.171062, -0.985260, -0.985260, 0.158041, -0.985260, -0.985260, 0.120959, -0.985260, -0.985260, 0.065463, -0.985260, -0.985260, 0.000000, -0.985260, -0.985260, -0.065463, -0.985260, -0.985260, -0.120959, -0.985260, -0.985260, -0.158041, -0.985260, -0.985260};
    
    int indices[2048] = {0,16,17,1,1,17,18,2,2,18,19,3,3,19,20,4,4,20,21,5,5,21,22,6,6,22,23,7,7,23,24,8,8,24,25,9,9,25,26,10,10,26,27,11,11,27,28,12,12,28,29,13,13,29,30,14,14,30,31,15,15,31,16,0,16,32,33,17,17,33,34,18,18,34,35,19,19,35,36,20,20,36,37,21,21,37,38,22,22,38,39,23,23,39,40,24,24,40,41,25,25,41,42,26,26,42,43,27,27,43,44,28,28,44,45,29,29,45,46,30,30,46,47,31,31,47,32,16,32,48,49,33,33,49,50,34,34,50,51,35,35,51,52,36,36,52,53,37,37,53,54,38,38,54,55,39,39,55,56,40,40,56,57,41,41,57,58,42,42,58,59,43,43,59,60,44,44,60,61,45,45,61,62,46,46,62,63,47,47,63,48,32,48,64,65,49,49,65,66,50,50,66,67,51,51,67,68,52,52,68,69,53,53,69,70,54,54,70,71,55,55,71,72,56,56,72,73,57,57,73,74,58,58,74,75,59,59,75,76,60,60,76,77,61,61,77,78,62,62,78,79,63,63,79,64,48,64,80,81,65,65,81,82,66,66,82,83,67,67,83,84,68,68,84,85,69,69,85,86,70,70,86,87,71,71,87,88,72,72,88,89,73,73,89,90,74,74,90,91,75,75,91,92,76,76,92,93,77,77,93,94,78,78,94,95,79,79,95,80,64,80,96,97,81,81,97,98,82,82,98,99,83,83,99,100,84,84,100,101,85,85,101,102,86,86,102,103,87,87,103,104,88,88,104,105,89,89,105,106,90,90,106,107,91,91,107,108,92,92,108,109,93,93,109,110,94,94,110,111,95,95,111,96,80,96,112,113,97,97,113,114,98,98,114,115,99,99,115,116,100,100,116,117,101,101,117,118,102,102,118,119,103,103,119,120,104,104,120,121,105,105,121,122,106,106,122,123,107,107,123,124,108,108,124,125,109,109,125,126,110,110,126,127,111,111,127,112,96,112,128,129,113,113,129,130,114,114,130,131,115,115,131,132,116,116,132,133,117,117,133,134,118,118,134,135,119,119,135,136,120,120,136,137,121,121,137,138,122,122,138,139,123,123,139,140,124,124,140,141,125,125,141,142,126,126,142,143,127,127,143,128,112,128,144,145,129,129,145,146,130,130,146,147,131,131,147,148,132,132,148,149,133,133,149,150,134,134,150,151,135,135,151,152,136,136,152,153,137,137,153,154,138,138,154,155,139,139,155,156,140,140,156,157,141,141,157,158,142,142,158,159,143,143,159,144,128,144,160,161,145,145,161,162,146,146,162,163,147,147,163,164,148,148,164,165,149,149,165,166,150,150,166,167,151,151,167,168,152,152,168,169,153,153,169,170,154,154,170,171,155,155,171,172,156,156,172,173,157,157,173,174,158,158,174,175,159,159,175,160,144,160,176,177,161,161,177,178,162,162,178,179,163,163,179,180,164,164,180,181,165,165,181,182,166,166,182,183,167,167,183,184,168,168,184,185,169,169,185,186,170,170,186,187,171,171,187,188,172,172,188,189,173,173,189,190,174,174,190,191,175,175,191,176,160,176,192,193,177,177,193,194,178,178,194,195,179,179,195,196,180,180,196,197,181,181,197,198,182,182,198,199,183,183,199,200,184,184,200,201,185,185,201,202,186,186,202,203,187,187,203,204,188,188,204,205,189,189,205,206,190,190,206,207,191,191,207,192,176,192,208,209,193,193,209,210,194,194,210,211,195,195,211,212,196,196,212,213,197,197,213,214,198,198,214,215,199,199,215,216,200,200,216,217,201,201,217,218,202,202,218,219,203,203,219,220,204,204,220,221,205,205,221,222,206,206,222,223,207,207,223,208,192,208,224,225,209,209,225,226,210,210,226,227,211,211,227,228,212,212,228,229,213,213,229,230,214,214,230,231,215,215,231,232,216,216,232,233,217,217,233,234,218,218,234,235,219,219,235,236,220,220,236,237,221,221,237,238,222,222,238,239,223,223,239,224,208,224,240,241,225,225,241,242,226,226,242,243,227,227,243,244,228,228,244,245,229,229,245,246,230,230,246,247,231,231,247,248,232,232,248,249,233,233,249,250,234,234,250,251,235,235,251,252,236,236,252,253,237,237,253,254,238,238,254,255,239,239,255,240,224,240,256,257,241,241,257,258,242,242,258,259,243,243,259,260,244,244,260,261,245,245,261,262,246,246,262,263,247,247,263,264,248,248,264,265,249,249,265,266,250,250,266,267,251,251,267,268,252,252,268,269,253,253,269,270,254,254,270,271,255,255,271,256,240,256,272,273,257,257,273,274,258,258,274,275,259,259,275,276,260,260,276,277,261,261,277,278,262,262,278,279,263,263,279,280,264,264,280,281,265,265,281,282,266,266,282,283,267,267,283,284,268,268,284,285,269,269,285,286,270,270,286,287,271,271,287,272,256,272,288,289,273,273,289,290,274,274,290,291,275,275,291,292,276,276,292,293,277,277,293,294,278,278,294,295,279,279,295,296,280,280};
    
    void drawPlayerCannon();
    void mouseMotion(int x, int y);
    void readMesh();
    void createMesh();
};
