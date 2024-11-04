//#include <ftxui/component/component.hpp>
//#include <ftxui/component/component_base.hpp>
//#include <ftxui/component/screen_interactive.hpp>
//#include <ftxui/dom/elements.hpp>
//#include <ftxui/dom/flexbox_config.hpp>
//#include <ftxui/dom/table.hpp>
//#include <ftxui/screen/color.hpp>
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace ftxui;
//
//// Helper function to create a button with a custom style
//ButtonOption Style() {
//    auto option = ButtonOption::Animated();
//    option.transform = [](const EntryState& s) {
//        auto element = text(s.label);
//        if (s.focused) {
//            element |= bold;
//        }
//        return element | center | borderEmpty | flex;
//    };
//    return option;
//}
//
//int main() {
//    auto screen = ScreenInteractive::Fullscreen();
//
//    int space_right = 30;   // Space for the resizable right edge
//    int space_bottom = 10;   // Space for the resizable bottom edge
//    int space_top = 5;      // Space for the resizable top edge
//    int space_left = 30;    // Space for the resizable left edge
//    int space_middle = 30;  // Space for the resizable middle section
//
//    // List of buildings with corresponding colors
//    std::vector<std::pair<std::string, Color>> buildings = {
//        {"1. Power Plant", Color::RedLight},
//        {"2. Water Plant", Color::Cyan},
//        {"3. Waste Management", Color::YellowLight},
//        {"4. School", Color::Green},
//        {"5. Hospital", Color::Cyan},
//        {"6. Town Hall", Color::Magenta},
//        {"7. Police Station", Color::GrayLight},
//        {"8. Airport", Color::White},
//        {"9. Train Station", Color::BlueLight},
//        {"10. Concrete Factory", Color::RedLight},
//        {"11. Steel Factory", Color::Cyan},
//        {"12. Forestry", Color::GreenLight},
//        {"13. Mall", Color::YellowLight},
//        {"14. Office", Color::CyanLight},
//        {"15. Shop", Color::MagentaLight},
//        {"16. Museum", Color::Orange1},
//        {"17. Park", Color::SpringGreen1},
//        {"18. House", Color::Yellow3},
//        {"19. Apartment", Color::HotPink},
//        {"20. Complex", Color::Cyan},
//        {"21. Road", Color::DarkSlateGray1}
//    };
//
//    // Create elements for each building
//    std::vector<Element> building_elements;
//    for (const auto& [name, color] : buildings) {
//        building_elements.push_back(text(name) | ftxui::color(color));
//    }
//
//    // Renderer for the building list with a heading and border
//    auto building_renderer = Renderer([&] {
//        return vbox({
//            text("Available Buildings") | bold | center,
//            separator(),
//            vbox(building_elements) | border
//        }) | bgcolor(Color::Black);
//    });
//
//    // Input field for user prompt
//    auto input_text = std::make_shared<std::string>();
//    auto input_component = Input(&*input_text, "Enter building number (1-21):");
//
//    // Label to display the selected building
//    auto selected_building = std::make_shared<std::string>("");
//
//    // Button to confirm the choice
//    auto button = Button("Confirm", [&] {
//        try {
//            int building_number = std::stoi(*input_text);
//            if (building_number >= 1 && building_number <= 21) {
//                *selected_building = "You have selected building: " + buildings[building_number - 1].first;
//            } else {
//                *selected_building = "Invalid building number!";
//            }
//        } catch (const std::exception& e) {
//            *selected_building = "Error: " + std::string(e.what());
//        }
//    }, Style());
//
//    // Renderer for the input field, button, and selected building label
//    auto input_renderer = Renderer(Container::Vertical({
//        input_component,
//        button
//    }), [&] {
//        return vbox({
//            text("User Input") | bold | center,
//            separator(),
//            input_component->Render() | border,
//            button->Render() | center,
//            text(*selected_building) | center | color(Color::Yellow)
//        }) | bgcolor(Color::Black);
//    });
//
//    // Placeholder for the map
//    auto map_renderer = Renderer([&] {
//        return text("Reserved for the map") | center | border;
//    });
//
//    // Buttons for the left upper panel
//    auto load_button = Button("Load", [] {
//        std::cout << "Load button pressed!" << std::endl;
//    }, Style());
//
//    auto save_button = Button("Save", [] {
//        std::cout << "Save button pressed!" << std::endl;
//    }, Style());
//
//    // Renderer for the left upper panel with load and save buttons
//    auto left_upper_renderer = Renderer(Container::Horizontal({
//        load_button,
//        save_button
//    }), [&] {
//        return hbox({
//            load_button->Render() | center,
//            separator() | size(WIDTH, EQUAL, 1), // Small gap between buttons
//            save_button->Render() | center
//        }) | center;
//    });
//
//    // Renderer for the right middle panel with city specs
//    auto city_specs_renderer = Renderer([&] {
//        return vbox({
//            text("How your city is doing") | bold | center,
//            separator(),
//            text("Morale: 40") | center,
//            text("Budget: 100000") | center,
//            text("Population: 20") | center,
//            text("Energy: 200") | center,
//            text("Water: 300") | center,
//            text("Building materials: 50") | center
//        }) | border | center;
//    });
//
//    // Center configuration for the resizable elements
//    auto center = FlexboxConfig()
//            .Set(FlexboxConfig::JustifyContent::Center)
//            .Set(FlexboxConfig::AlignContent::Center);
//
//    // Split the top panel into three sections
//    auto top_renderer = ResizableSplitLeft(
//        left_upper_renderer,
//        ResizableSplitRight(
//            city_specs_renderer,
//            Renderer([&] { return flexbox({text("Notifications")}, center); }),
//            &space_middle),
//        &space_left);
//
//    // Make content_renderer resizable with top, right, and bottom panels
//    auto content_renderer = ResizableSplitRight(
//            building_renderer, // Use the building renderer directly
//            map_renderer, // Use the map renderer for the right panel
//            &space_right);
//    content_renderer = ResizableSplitBottom(
//            input_renderer, // Use the input renderer for the bottom panel
//            content_renderer, &space_bottom);
//    content_renderer = ResizableSplitTop(
//            top_renderer, // Use the top renderer for the top panel
//            content_renderer, &space_top);
//
//    // Run the screen loop
//    screen.Loop(content_renderer);
//
//    return 0;
//}