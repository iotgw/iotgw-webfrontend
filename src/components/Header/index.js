import React from "react";
import "./index.css";
import {
  Nav,
  NavItem,
  NavLink,
  Navbar,
  Collapse,
  NavbarToggler,
  NavbarBrand
} from "reactstrap";
import { Link } from "react-router-dom";

export class Header extends React.Component {
  constructor(props) {
    super(props);

    super(props);

    this.toggleNavbar = this.toggleNavbar.bind(this);
    this.state = {
      collapsed: true
    };
  }
  getClassName(path) {
    var p = window.location.hash.replace("#", "");
    return p === path ? "linkActive" : "linkNormal";
  }
  toggleNavbar() {
    this.setState({
      collapsed: !this.state.collapsed
    });
  }
  render() {
    return (
      <div className="header">
        <Navbar expand="md" light>
          <NavbarBrand href="/">
            <span className="app-logo logo">
              Open Source IoT Gateway
            </span>
          </NavbarBrand>
          <NavbarToggler onClick={this.toggleNavbar} />
          <Collapse isOpen={!this.state.collapsed} navbar>
            <Nav className="ml-auto" navbar>
              <NavItem>
                <NavLink
                  tag={Link}
                  to="/settings"
                  disabled={window.location.hash.includes("/settings")}
                  className={this.getClassName("/")}
                >
                  Settings
                </NavLink>
              </NavItem>
              <NavItem>
                <NavLink
                  tag={Link}
                  to="/wifi"
                  disabled={window.location.hash.includes("/wifi")}
                  className={this.getClassName("/station")}
                >
                  WiFi
                </NavLink>
              </NavItem>
            </Nav>
          </Collapse>
        </Navbar>
      </div>
    );
  }
}

export default Header;
